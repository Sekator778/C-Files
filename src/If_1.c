#include <stdio.h>
#include <math.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are now signed up!");
    }
    else
    {
        printf("You are too young to sign up!");
    }
    
    return 0;
}