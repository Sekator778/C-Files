#include <stdio.h>

int main() {
    char name[] = "Alex";
    int age = 46;
    char grade = 'A';
    float gpa = 12.034;

    printf("Hello %s\n", name);
    printf("Your age is %d\n", age);
    printf("Computer science has grade: %f\
    t", gpa);
    printf("It's a %c grade", grade);

    return 0;
}