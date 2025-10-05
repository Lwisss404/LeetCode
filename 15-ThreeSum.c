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

int binarySearch(int* nums, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return 1;
        else if (nums[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return 0;
}

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSize) {
    *returnSize = 0;
    if (numsSize < 3) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 1000;
    int** resultArray = malloc(capacity * sizeof(int *));
    *returnColumnSize = malloc(capacity * sizeof(int));
    if (resultArray == NULL || (*returnColumnSize) == NULL) return NULL;

    for (int i = 0; i < numsSize - 2; i++) {
        //skips duplicates
        if (i > 0 && *(nums + i) == *(nums + i - 1)) continue;

        for (int j = i + 1; j < numsSize - 1; j++) {
            //also skips duplicates
            if (j > i + 1 && *(nums + j) == *(nums + j - 1)) continue;
            int complement = -nums[i] - nums[j];
            int foundComp = binarySearch(nums, j + 1, numsSize - 1, complement);

            int* triplet = malloc(3 * sizeof(int));
            if (foundComp) {
                //complement found
                triplet[0] = nums[i];
                triplet[1] = nums[j];
                triplet[2] = complement;
                qsort(triplet, 3, sizeof(int), cmp);

                //dynamic space reallocation in case of overflow
                if (*returnSize >= capacity) {
                    capacity *= 1.5;
                    resultArray = realloc(resultArray, capacity * sizeof(int *));
                    *returnColumnSize = realloc(*returnColumnSize, capacity * sizeof(int));
                }
                resultArray[*returnSize] = triplet;
                (*returnColumnSize)[*returnSize] = 3;
                (*returnSize)++;
            } else {
                free(triplet);
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