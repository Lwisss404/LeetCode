#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int lengthOfLongestSubstring(char *s) {
    int length = strlen(s);
    int left = 0, maxLength = 0, currLength;
    char lastPositions[256];

    for (int i = 0; i < 256; i++) { lastPositions[i] = -1; }

    for (int i = 0; i < length; i++) {
        char ch = s[i];
        /* printf("the Character: %c\n", ch);
        printf("Its last position: %d\n", lastPositions[(unsigned char)ch]);
        printf("Left slider position: %d\n", left); */

        //checking if ch exists in our current substring by comparing its latest recorded position with the current position
        if (lastPositions[(unsigned char)ch] >= left) {
            left = lastPositions[(unsigned char)ch] + 1;
        }
        /* printf("updated Left slider position: %d\n", left); */

        //updating the latest recorded position of the current ch
        lastPositions[(unsigned char)ch] = i;
        /* printf("updated last position: %d\n", lastPositions[(unsigned char)ch]); */

        //updating the max length vriable with every iteration
        currLength = i - left + 1;
        /* printf("Iterator: %d\n", i);
        printf("Max Length: %d\n", maxLength); */
        maxLength = (currLength > maxLength) ? currLength : maxLength;
        /* printf("Current Length: %d\n", currLength); */
    }
    return maxLength;
}

int main() {
    char s[10];
    printf("Give a String: ");
    scanf("%9s", s);
    printf("%d", lengthOfLongestSubstring(s));
    
}