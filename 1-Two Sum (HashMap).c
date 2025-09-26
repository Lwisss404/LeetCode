#include <stdlib.h>
#include <stdio.h>

#define HASH_SIZE 1000

typedef struct Hashnode {
    int key;
    int index;
    struct Hashnode* next;
} Hashnode;


void fillArray(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        *(nums + i) = 1 + (rand() % 10 + 1 - 1);
    }
}

void displayArray(int *nums, int numsSize) {
    printf("[");
    int i;
    for (i = 0; i < numsSize - 2; i++) {
        printf("%d, ", *(nums + i));
    }
    printf("%d]\n", *(nums + i + 1));
}

int hash(int key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

void insertHashNode(Hashnode** HashMap, int key, int index) {
    int h = hash(key);
    Hashnode* newNode = malloc(sizeof(Hashnode));
    newNode->key = key;
    newNode->index = index;
    newNode->next = HashMap[h];
    HashMap[h] = newNode;
}

int searchHashMap(Hashnode** HashMap, int key) {
    int h = hash(key);
    Hashnode* Node = malloc(sizeof(Hashnode));
    Node = HashMap[h];
    while (Node) {
        if (Node->key == key) return Node->index;
        Node = Node->next;
    }
    return -1; //Nicht gefunden
}

void freeHashMap(Hashnode** HashMap) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Hashnode* Node = HashMap[i];
        while (Node) {
            Hashnode* tmp = Node;
            Node = Node->next;
            free(tmp);
        }
    }
}

int* twoSums(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int compliment, idx;
    int* resArray = malloc(*returnSize * sizeof(int));
    if (!resArray) return NULL;
    Hashnode* HashMap[HASH_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        compliment = target - *(nums + i);
        idx = searchHashMap(HashMap, compliment);

        if (idx != -1) {
            *(resArray) = i;
            *(resArray + 1) = idx;
            return resArray;
        }
        insertHashNode(HashMap, *(nums + i), i);
    }

    *returnSize = 0;
    freeHashMap(HashMap);
    free(resArray);
    free(nums);
    return NULL;
}

int main() {
    
    int numsSize = 5 + (rand() % (10 - 5 + 1));
    int* nums = malloc(numsSize * sizeof(int));
    if (!nums) return 0;
    int* returnSize = malloc(sizeof(int));
    if (!returnSize) return 0;
    
    fillArray(nums, numsSize);
    displayArray(nums, numsSize);

    int* resArray = twoSums(nums, numsSize, 5 + (rand() % (15 - 5 + 1)), returnSize);
    if (resArray) {
        printf("[%d, %d]\n", resArray[0], resArray[1]);
    } else {
        printf("No Solution Found!");
    }

    return 0;
}