#include <stdio.h>

int main() {
   char x = 'X';
   char y = 'Y';

    x = y ^ x;
    y = x ^ y;
    x = y ^ x;

    printf("x = %c\n", x);
    printf("y = %c\n", y);
   
    return 0;
}