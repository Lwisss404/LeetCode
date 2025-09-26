#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int value;
    int index;
} Pair;

void fillArray(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        *(nums + i) = 1 + (rand() % 10);
    }
}

void displayArray(int *nums, int numsSize) {
    int i;
    printf("[");
    for (i = 0; i < numsSize-2; i++) {
        printf("%d, ", *(nums + i));
    }
    printf("%d] \n", *(nums + i + 1));
}

int comparePairs(const void* a,const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int binarySearch(Pair* nums, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((*(nums + mid)).value == target) return mid;
        if ((*(nums + mid)).value < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;  // immer 2 Werte zurück
    int* resArray = malloc(2 * sizeof(int));
    if (!resArray) return NULL; // malloc-Fehler abfangen
    
    Pair* pairArray = malloc(numsSize * sizeof(Pair));
    if (!pairArray) return NULL; // malloc-Fehler abfangen

    for (int i = 0; i < numsSize; i++) {
        pairArray[i].value = *(nums + i);
        pairArray[i].index = i;
    }

    free(nums);
    qsort(pairArray, numsSize, sizeof(Pair), comparePairs);

    for (int i = 0; i < numsSize; i++) {
        int compliment = target - pairArray[i].value;
        int idx = binarySearch(pairArray, i + 1, numsSize - 1, compliment);
        if (idx != -1) {
            resArray[0] = pairArray[i].index;
            resArray[1] = pairArray[idx].index;
            return resArray;
        }
    }
    
    // Falls nichts gefunden wurde
    *returnSize = 0;
    free(pairArray);
    return NULL;
}

int main() {
    int numsSize = 5 + (rand() % (10 - 5 + 1));
    int* nums = malloc(numsSize * sizeof(int));
    int* returnSize = malloc(sizeof(int));
    fillArray(nums, numsSize);
    displayArray(nums, numsSize);
    int* resArray = twoSum(nums, numsSize, 9, returnSize);
    if (!resArray) return 0;
    printf("[%d, %d]", resArray[0], resArray[1]);
    free(returnSize);
    free(resArray);
    return 0;
}