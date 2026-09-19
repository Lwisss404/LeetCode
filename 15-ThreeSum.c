#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
void fillArray(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        *(nums + i) = (rand() % 19) - 9;
    }
}

void displayArray(int* nums, int numsSize) {
    printf("[");
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
        if (i < numsSize - 1) printf(", ");
    }
    printf("]\n");
}

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSize) {
    *returnSize = 0;
    if (numsSize < 3) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 64;
    int** resultArray = malloc(capacity * sizeof(int *));
    *returnColumnSize = malloc(capacity * sizeof(int));
    if (resultArray == NULL || (*returnColumnSize) == NULL) return NULL;

    for (int i = 0; i < numsSize - 2; i++) {
        //skips duplicates
        if (i > 0 && *(nums + i) == *(nums + i - 1)) continue;
        //break is all numbers are positiv or negative
        if (nums[i] > 0 || nums[numsSize - 1] < 0) break;
        
        int target = -nums[i];
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int complement = nums[left] + nums[right];
            if(complement == target) {
                //complement found
                int* triplet = malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                
                //dynamic space reallocation in case of overflow
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    resultArray = realloc(resultArray, capacity * sizeof(int *));
                    *returnColumnSize = realloc(*returnColumnSize, capacity * sizeof(int));
                }
                resultArray[*returnSize] = triplet;
                (*returnColumnSize)[*returnSize] = 3;
                (*returnSize)++;
                left++;
                right--;

                //skipping dupes
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } else if (complement < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return resultArray;
}

int main() {
    srand((unsigned)time(NULL));

    int numsSize = 5 + (rand() % (10 - 5 + 1));
    int* nums = malloc(numsSize * sizeof(int));
    if (nums == NULL) { return 1; }
    
    fillArray(nums, numsSize);
    displayArray(nums, numsSize);
    
    int returnSize;
    int* returnColumnSize;
    int** resultArray = threeSum(nums, numsSize, &returnSize, &returnColumnSize);

    for(int i = 0; i < returnSize; i++) {
        displayArray(resultArray[i], 3);
        free(resultArray[i]);
    }
    
    free(nums);
    free(resultArray);
    free(returnColumnSize);

    return 0;
}