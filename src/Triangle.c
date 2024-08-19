#include <stdio.h>
#include <math.h>

int main() {
    const double PI = 3.14159326;

    double A, B, C;

    printf("Enter side A: ");    
    scanf("%lf", &A);
    
    printf("Enter side B: ");    
    scanf("%lf", &B);
    C = sqrt(A*A + B*B);

    printf("\nSide C: %lf", C);
    return 0;
}