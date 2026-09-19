#include <stdlib.h>
#include <stdio.h>


typedef struct listNode {
    int value;
    struct listNode* next;
} listNode;

listNode* createList(int Number) {
    listNode *nodeHead = malloc(sizeof(listNode));
    if (!nodeHead) return NULL;
    listNode *currentNode = nodeHead;

    nodeHead->value = Number % 10;
    nodeHead->next = NULL;
    Number = Number / 10;
    
    while (Number > 0) {
        listNode* newNode = malloc(sizeof(listNode));
        if (!newNode) return NULL;
        newNode->value = Number % 10;
        newNode->next = NULL;
        currentNode->next = newNode;
        currentNode = newNode;
        Number = Number / 10;
    }
    return nodeHead;
}

void displayListRec(listNode* List) {
    if (List == NULL) return;
    displayListRec(List->next);
    printf("[%d] - ", List->value);
}

void displayListIte(listNode* List) {
    for (listNode* curr = List; curr != NULL; curr = curr->next) {
        printf("[%d]", curr->value);
        if (curr->next != NULL) printf(" - ");
    }
}

void freeList(listNode* List) {
    while (List != NULL) {
        listNode* tmp = List;
        List = List->next;
        free(tmp);
    }
}

int sumTwoNumbers(int x, int y, int* overcharge) {
    int sum;
    if (x + y + *overcharge > 9) {
        sum = x + y + *overcharge - 10;
        *overcharge = 1;
    } else {
        sum = x + y + *overcharge;
        *overcharge = 0;
    }
    return sum;
}

listNode* addtwoNumbers(listNode* l1, listNode* l2) {
    int overcharge = 0;
    listNode* headOfSum = malloc(sizeof(listNode));
    headOfSum->next = NULL;
    listNode* currentNodeOfSum = headOfSum;

    listNode* currentNode1 = l1;
    listNode* currentNode2 = l2;
    currentNodeOfSum->value = sumTwoNumbers(currentNode1->value, currentNode2->value, &overcharge);

    currentNode1 = currentNode1->next;
    currentNode2 = currentNode2->next;
    
    while (currentNode1 != NULL || currentNode2 != NULL) {
        listNode* newNode = malloc(sizeof(listNode));
        newNode->next = NULL;

        if (currentNode1 == NULL) {
            newNode->value = sumTwoNumbers(0, currentNode2->value, &overcharge);
        } else if (currentNode2 == NULL) {
            newNode->value = sumTwoNumbers(currentNode1->value, 0, &overcharge);
        } else {
            newNode->value = sumTwoNumbers(currentNode1->value, currentNode2->value, &overcharge);
        }

        currentNodeOfSum->next = newNode;
        currentNodeOfSum = newNode;
        currentNode1 = (currentNode1) ? currentNode1->next : NULL;
        currentNode2 = (currentNode2) ? currentNode2->next : NULL;
    }
    
    if (overcharge > 0) {
        listNode* newNode = malloc(sizeof(listNode));
        newNode->value = overcharge;
        newNode->next = NULL;
        currentNodeOfSum->next = newNode;
    }
    return headOfSum;
}

int main() {
    int Number1, Number2;
    printf("Give me a number: ");
    scanf("%d", &Number1);
    printf("Give me a second number: ");
    scanf("%d", &Number2);
    if (Number1 < 0) Number1 = -Number1;
    if (Number2 < 0) Number2 = -Number2;

    listNode* l1 = createList(Number1);
    listNode* l2 = createList(Number2);

    displayListRec(l1);
    printf("\b\b \n");
    displayListRec(l2);
    printf("\b\b \n");

    listNode* resArray = addtwoNumbers(l1, l2);
    displayListIte(resArray);
    
    freeList(l1);
    freeList(l2);
    freeList(resArray);

    return 0;
}