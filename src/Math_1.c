#include <stdio.h>
#include <math.h>

int main() {
    double A = sqrt(9);
    double B = pow(2, 4);
    int C = round(3.1415);
    int D = ceil(3.14);
    int E = floor(3.98);

    double F = fabs(-100);
    double G = log(3);
    double H;

    printf("sqrt: %lf", A);    
    printf("\npow: %.3f", B);
    printf("\nround: %d", C);
    printf("\ncell: %d", D);
    printf("\nfloor: %d", E);
    printf("\nfabs: %lf", F);
    printf("\nlog: %lf", G);

    return 0;
}