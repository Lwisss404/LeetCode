#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;  // immer 2 Werte zurück
    int* resArray = malloc(2 * sizeof(int));
    if (!resArray) return NULL; // malloc-Fehler abfangen

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                resArray[0] = i; // Index zurückgeben (wie in LeetCode erwartet)
                resArray[1] = j;
                return resArray;
            }
        }
    }

    // Falls nichts gefunden wurde
    *returnSize = 0;
    free(resArray);
    return NULL;
}