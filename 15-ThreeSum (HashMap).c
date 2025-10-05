#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HASH_SIZE 3000

typedef struct Hashnode {
    int key;
    struct Hashnode* next;
} Hashnode;

void fillArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        /*printf("Give a number: ");
        scanf("%d", nums + i);*/
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

int hash(int key) {
    if (key < 0) key = -key;
    return (key % HASH_SIZE);
}

void fillHashTable(Hashnode** table, int key) {
    int h = hash(key);
    Hashnode* newNode = malloc(sizeof(Hashnode));
    if (newNode == NULL) { return; }
    newNode->key = key;
    newNode->next = table[h];
    table[h] = newNode;
}

int searchHashTable(Hashnode** table, int key) {
    int h = hash(key);
    Hashnode* Node = table[h];
    while (Node != NULL) {
        if (Node->key == key) return true;
        Node = Node->next;
    }
    return false;
}

void freeHashTable(Hashnode** table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Hashnode* Node = table[i];
        while (Node != NULL) {
            Hashnode* temp = Node;
            Node = Node->next;
            free(temp);
        }
    }
}

int cmp (const void* x, const void* y) {
    return *(int *)x - *(int *)y;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 1000;
    int** returnArray = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    if (returnArray == NULL || *returnColumnSizes == NULL) return NULL;

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && *(nums + i) == *(nums + i - 1)) continue;

        Hashnode* hashMap[HASH_SIZE] = {0};

        for (int j = i + 1; j < numsSize; j++) {
            int complement = -nums[i] - nums[j];

            int* triplet = malloc(3 * sizeof(int));
            if (searchHashTable(hashMap, complement)) {
                triplet[0] = nums[i];
                triplet[1] = complement;
                triplet[2] = nums[j];
                qsort(triplet, 3, sizeof(int), cmp);
                

                int duplicate = false;
                for (int k = 0; k < *returnSize; k++) {
                    if (
                        triplet[0] == (returnArray[k])[0]
                        && triplet[1] == (returnArray[k])[1]
                        && triplet[2] == (returnArray[k])[2]
                    ) { duplicate = true; break;}
                }

                if (!duplicate) {
                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        returnArray = realloc(returnArray, capacity * sizeof(int *));
                        *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                    }
                    returnArray[*returnSize] = triplet;
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                }
            } else {
                fillHashTable(hashMap, nums[j]);
            }
        }
        freeHashTable(hashMap);
    }
    return returnArray;
}

int main() {
    int numsSize = 5 + (rand() % (10 - 5 + 1));
    int* nums = malloc(numsSize * sizeof(int));
    
    fillArray(nums, numsSize);
    displayArray(nums, numsSize);

    int returnSize;
    int* returnColumnSizes;
    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }
    free(nums);
    free(result);
    free(returnColumnSizes);
    return 0;
}