#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    //mapping values and corresponding roman symboles
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symboles[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    char* romanInt = malloc(200 * sizeof(char));
    if (!romanInt) return NULL;
    romanInt[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(romanInt, symboles[i]);
            printf("%s\n", romanInt);
            num-=values[i];
        }
    }

    return romanInt;
}

int main() {
    //initializing values
    int num;
    printf("Give a number: ");
    scanf("%d", &num);
    char* romanInt = intToRoman(num);
    printf("%s", romanInt);
    free(romanInt);
    return 0;
}