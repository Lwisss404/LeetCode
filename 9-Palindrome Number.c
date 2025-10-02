#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x / 10 == 0) return true;

    int digits = (int)log10(x);
    int divisor = (int)pow(10, digits);

    while (x != 0) {
        int leftDigit = x / divisor;
        int rightDigit = x % 10;

        if (rightDigit != leftDigit) { return false; }

        x = (x % divisor) / 10;
        divisor /= 100;

        if (x == 0) break;
    }

    return true;
} 

int main() {
    int x;
    printf("Give a number: ");
    scanf("%d", &x);

    bool result = isPalindrome(x);
    printf("The number %d is %sa Palindrome\n", x, result ? "" : "not ");
    return 0;
}