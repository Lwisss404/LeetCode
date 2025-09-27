#include <stdlib.h>
#include <stdio.h>

int cmp (const void* x, const void* y) {
    return *(int *)x - *(int *)y;
}

int max (int x, int y) {
    if (x >= y) return x;
    else return y;
}

void fillArray (int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        *(nums + i) = 0 + (rand() % (100 - 0 + 1));
    }
}

void displayArray (int* nums, int numsSize) {
    int i;
    printf("Length is : %d\n[", numsSize);
    for (i = 0; i < numsSize - 1; i++) {
        printf("%d, ", *(nums + i));
    }
    printf("%d]\n", *(nums + i));
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mergedNumsSize = nums1Size + nums2Size;
    int *mergedNums = malloc(mergedNumsSize * sizeof(int));
    if (!mergedNums) return -1;

    int j = 0;

    for (int i = 0; i < max(nums1Size, nums2Size); i++) {
        if (i < nums1Size) {
            *(mergedNums + j) = *(nums1 + i);
            j++;
        }
        if (i < nums2Size) {
            *(mergedNums + j) = *(nums2 + i);
            j++;
        }
    }

    double median;
    if (mergedNumsSize % 2 == 0) {
        median = (*(mergedNums + (mergedNumsSize / 2)) + *(mergedNums + (mergedNumsSize / 2) - 1)) / 2;
    } else {
        median =  *(mergedNums + (mergedNumsSize / 2));
    }

    displayArray(mergedNums, mergedNumsSize);
    free(mergedNums);
    return median;
}

int main() {
    int nums1Size = 1 + (rand() % (10 + 1 - 1));
    int nums2Size = 1 + (rand() % (10 + 1 - 1));
    int *nums1 = malloc(nums1Size * sizeof(int));
    if (!nums1) return 0;
    int *nums2 = malloc(nums2Size * sizeof(int));
    if (!nums2) return 0;

    fillArray(nums1, nums1Size);
    fillArray(nums2, nums2Size);

    displayArray(nums1, nums1Size);
    displayArray(nums2, nums2Size);

    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    displayArray(nums1, nums1Size);
    displayArray(nums2, nums2Size);

    printf("The median is: %lf", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

    free(nums1);
    free(nums2);

}