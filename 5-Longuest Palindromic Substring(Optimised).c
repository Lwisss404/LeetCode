#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int length = strlen(s);
    if (length == 0) return "";

    int l, r;
    int start = 0, maxLength = 0;

    for (int i = 0; i < length; i++) {
        //cheching for odd-length palidrome
        l = i, r = i;
        while (l >= 0 && r < length && s[l] == s[r]) {
            if (r - l + 1 > maxLength) {
                start = l;
                maxLength = r - l + 1;
            }
            l--;
            r++;
        }

        //checking for even-length palindromes
        l = i, r = i + 1;
        while (l >= 0 && r < length && s[l] == s[r]) {
            if (r - l + 1 > maxLength) {
                start = l;
                maxLength = r - l + 1;
            }
            l--;
            r++;
        }
    }
    char *longuestPal = malloc((maxLength + 1) * sizeof(int));
    strncpy(longuestPal, s + start, maxLength);
    longuestPal[maxLength] = '\0';
    return longuestPal;
}

int main() {
    char s[10000];
    printf("Give a String: ");
    scanf("%9999s", s);
    char *longPal = longestPalindrome(s);
    printf("%s", longPal);
    free(longPal);
    return 0;
}