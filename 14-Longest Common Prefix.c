#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int maxLen = strlen(strs[0]);
    char* lCP = malloc((maxLen + 1) * sizeof(char));
    if (!lCP) { return NULL; }

    int idx = 0;
    while (idx < maxLen) {
        char tmp = (strs[0])[idx];
        for (int i = 0; i < strsSize; i++) {
            if ((idx >= strlen(strs[i])) || (tmp != (strs[i])[idx])) {
                lCP[idx] = '\0';
                return lCP;
            }
        }
        lCP[idx++] = tmp;
    }
    lCP[idx] = '\0';
    return lCP;
}

int main() {
    int strsLength = 3;
    
    char** strs = malloc(strsLength * sizeof(char *));

    for (int i = 0; i < strsLength; i++) {
        strs[i] = malloc((strsLength + 1) * sizeof(char));
        if (!strs[i]) { return 0; }
        printf("Give a string: ");
        scanf("%200s", strs[i]);
    }

    char* lCP = longestCommonPrefix(strs, strsLength);
    printf("Longest common prefix is: %s", lCP);

    for (int i = 0; i < strsLength; i++) {
        free(strs[i]);
    }
    free(strs);
    free(lCP);

    return 0;
}