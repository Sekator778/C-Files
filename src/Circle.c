#include <stdio.h>
#include <math.h>

int main() {
    const double PI = 3.14159326;

    double radius, circunference, area;

    printf("Enter the radius of a circle: ");    
    scanf("%lf", & radius);
    circunference = 2 * PI * radius;
    area = PI * pow(radius, 2);

    printf("circumference: %lf", circunference);
    printf("\narea: %lf", area);
    return 0;
}