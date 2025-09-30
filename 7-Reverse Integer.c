#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

int reverse(int x){

    if (x / 10 == 0) { return x; }

    int revX = 0;
    int sign = (x >= 0) ? 1 : -1;
    x *= sign;

    while (x != 0) {
        int digit = x % 10;

        if (revX > (INT_MAX - digit) / 10) {
            return 0;
        }

        revX = revX * 10 + digit;
        x /= 10;
    }

    return revX * sign;
}

int main() {
    int x;
    printf("Give a number: ");
    scanf("%d", &x);
    if (x <= -pow(2, 31) || x >= pow(2, 31)) { return 0; }

    int reverseX = reverse(x);
    printf("Reverse %d is %d.", x, reverseX);

    return 0;
}