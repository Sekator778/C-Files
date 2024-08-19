#include <stdio.h>
#include <math.h>

int main() {
    char grade;

    printf("Enter a letter grade: ");
    scanf("%c", &grade);

    switch (grade)
    {
    case 'A':
        printf("Perfect!\n");
        break;
    case 'B':
        printf("You did good!");
        break;
    case 'C':
        printf("You did OK!\n");
        break;
    case 'D':
        printf("At least it's not an F!");
        break;
    case 'F':
        printf("YOU FAILED!");
        break;
    default:
        printf("Don't allow this");
        break;
    }
    
    return 0;
}