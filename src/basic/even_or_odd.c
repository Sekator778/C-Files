#include <stdio.h>
#include <math.h>

int main() {
    double num;

    printf("Enter a number: ");
    scanf("%lf", &num);
    int num2 = round(num);
    printf("\nhere num2: %d\n", num2);
    if (num2 & 1)
    {
        printf("it's odd number");
    } else
    {
        printf("it's even number");
    }
    return 0;
}