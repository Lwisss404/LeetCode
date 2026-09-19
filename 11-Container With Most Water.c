#include <stdlib.h>
#include <stdio.h>
 
void fillTable(int* T, int n) {
    for (int i = 0; i < n; i++) {
        printf("Give Number: ");
        scanf("%d", &T[i]);
    }
}

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int maxArea(int* height, int hightSize) {
    int max = 0, currArea;
    int left = 0, right = hightSize - 1;

    while (right >= left) {
        currArea = (right - left) * min(height[right], height[left]);
        max = (max > currArea) ? max : currArea;
        if (height[right] >= height[left]) {
            left++;
        } else {
            right--;
        }
    }
    return max;
}


int main() {
    //initializing values
    //int heightSize = 2 + (rand() % (20 - 5 + 1));
    int heightSize = 9;
    int *height = malloc(heightSize * sizeof(int));

    fillTable(height, heightSize);
    int cWMW = maxArea(height, heightSize);
    printf("Max Area is :%d", cWMW);
    free(height);
    return 0;
}