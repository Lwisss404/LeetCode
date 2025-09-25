#include <stdlib.h>
#include <stdio.h>

void fillArray(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        *(nums + i) = 1 + (rand() % 10);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;  // immer 2 Werte zurück
    int* resArray = malloc(2 * sizeof(int));
    if (!resArray) return NULL; // malloc-Fehler abfangen

    printf("Debugg: \n");
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            printf("%d[Element n:%d] + %d[Element n:%d] = %d\n", nums[i], i+1, nums[j], j+1, nums[i] + nums[j]);
            if (*(nums + i) + *(nums + j) == target) {
                *(resArray) = *(nums + i);
                *(resArray + 1) = *(nums + j);
                return resArray;
            }
        }
    }

    // Falls nichts gefunden wurde
    *returnSize = 0;
    return NULL;
}

int main() {
    int numsSize = 5 + (rand() % (10 - 5 + 1));
    int* nums = malloc(numsSize * sizeof(int));
    int* returnSize = malloc(sizeof(int));
    fillArray(nums, numsSize);
    int* resArray = twoSum(nums, numsSize, 9, returnSize);
    if (!resArray) return 0;
    printf("[%d, %d]", resArray[0], resArray[1]);
    free(nums);
    free(returnSize);
    free(resArray);
    return 0;
}