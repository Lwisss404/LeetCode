#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 
int myAtoi(char* s) {
    int lengthS = strlen(s);
    if (lengthS < 1) return 0;
    if (lengthS == 1) {
        if (isdigit(s[0])) return s[0] - '0';
        else return 0;
    }

    //skipping the empty spaces at the start of the string
    int idx = 0;
    while (s[idx] == ' ' && idx < lengthS) {
        idx++;
    }

    //end reaches with all characters being an empty space
    if (idx == lengthS) return 0;

    //cheching the first 'real' character
    int sign = 1;
    if (!isdigit(s[idx]) && s[idx] != '+' && s[idx] != '-') {
        return 0;
    } else if (s[idx] == '-') {
        sign = -sign;
        idx++;
    } else if (s[idx] == '+') {
        idx++;
    } else {}

    //converting all digits until we reach the end of the string or a non digit character
    int x = 0;
    while (idx < lengthS && isdigit(s[idx])) {
        //checking overflow
        int digit = s[idx] - '0';
        if (x > (INT_MAX - digit) / 10) {
            return (sign == -1) ? INT_MIN : INT_MAX;
        }
        x = x * 10 + digit;
        idx++;
    }

    return x * sign;
}

int main() {

    char string[201];
    printf("Give a string: ");
    scanf("%200s", string);
    string[201] == '\0';

    int x = myAtoi(string);
    printf("%s to integer is %d", string, x);
    return 0;
}