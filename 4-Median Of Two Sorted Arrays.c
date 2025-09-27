#include <stdlib.h>
#include <stdio.h>

int cmp (const void* x, const void* y) {
    return *(int *)x - *(int *)y;
}

void fillArray (int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        *(nums + i) = 1 + (rand() % (10 - 1 + 1));
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

    int i = 0, j = 0, k = 0;

    //Adding numbers in order to the new list until one array is empty
    while (i < nums1Size && j < nums2Size) {
        if (*(nums1 + i) <= *(nums2 + j)) {
            *(mergedNums + k) = *(nums1 + i);
            i++;
        } else {
            *(mergedNums + k) = *(nums2 + j);
            j++;
        }
        k++;
    }

    //cheching which array still contains numbers and adding then in order
    while (i < nums1Size) mergedNums[k++] = nums1[i++];
    while (j < nums2Size) mergedNums[k++] = nums2[j++];

    double median;
    if (mergedNumsSize % 2 == 0) {
        median = ((double)*(mergedNums + (mergedNumsSize / 2)) + (double)*(mergedNums + (mergedNumsSize / 2) - 1)) / 2;
    } else {
        median =  (double)*(mergedNums + (mergedNumsSize / 2));
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
    return 0;
}