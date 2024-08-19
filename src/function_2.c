#include <stdio.h>

int findMax(int a, int b)
{
    return a > b ? a : b;
}

int main() {
    int a, b;
    printf("Input first value:");
    scanf("%d", &a);
    
    printf("Input second value:");
    scanf("%d", &b);

    printf("Value %d is bigger.", findMax(a, b));

    return 0;
}