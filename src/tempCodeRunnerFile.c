#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num & 1)
    {
        printf("it's odd number");
    } else
    {
        printf("it's even number");
    }
    
    
    return 0;
}