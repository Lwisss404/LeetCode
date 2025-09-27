#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    int length = strlen(s);
    if (length == 0) return "";
    int maxLen = 1, start = 0;

    bool dp[length][length];
    memset(dp, 0, sizeof(dp));

    //setting all 1-length substrings as palindromes
    for (int i = 0; i < length; i++) { dp[i][i] = true; }

    //checking the 2 character substrings
    for (int i = 0; i < length - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    //recursive cheching the 3+ length substrings
    for (int len = 3; len <= length; len++) {
        for (int i = 0; i <= length - len; i++) {
            int j = i + len - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }

    char* result = malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}

int main() {
    char s[10000];
    printf("Enter a string: ");
    scanf("%9999s", s);

    char* longestPal = longestPalindrome(s);
    printf("Longest palindrome: %s\n", longestPal);
    free(longestPal);

    return 0;
}