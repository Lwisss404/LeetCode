#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int length = strlen(s);
    int start = 0, end = 0;
    int i, j;

    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (isPalindrome(s, i, j) && ((j - i) > (end - start))) {
                start = i;
                end = j;
            }
        }
    }
    char *longestPal = malloc((end - start + 2) * sizeof(char));
    j = 0;
    for (i = start; i <= end; i++) {
        longestPal[j] = s[i];
        j++;
    }
    longestPal[j] = '\0';
    return longestPal;
}

int main() {
    char s[10000];
    printf("Give a String: ");
    scanf("%9999s", s);
    //char* longPal = malloc(sizeof(char));
    char *longPal = longestPalindrome(s);
    printf("%s", longPal);
    free(longPal);
    return 0;
}