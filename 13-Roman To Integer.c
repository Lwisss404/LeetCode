#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int convertRomanToInteger(char ch) {
    int x;
    
    switch (ch) {
        case 'M': x = 1000; break;
        case 'D': x = 500; break;
        case 'C': x = 100; break;
        case 'L': x = 50; break;
        case 'X': x = 10; break;
        case 'V': x = 5; break;
        case 'I': x = 1; break;
    }

    return x;
}

int romanToInt(char* s) {
    int length = strlen(s);
    int num = 0;

    for (int i = 0; i < length; i++) {
        if ((i + 1 < length) && (convertRomanToInteger(s[i]) < convertRomanToInteger(s[i+1]))) {
            num += (convertRomanToInteger(s[i+1]) - convertRomanToInteger(s[i]));
            i++;
        } else {
            num += convertRomanToInteger(s[i]);
        }
    }

    return num;
}

int main() {
    //intializing values
    char romanString[21];
    printf("Give a roman number: ");
    scanf("%20s", romanString);

    int num = romanToInt(romanString);
    printf("%s to integer is %d", romanString, num);

    return 0;
}