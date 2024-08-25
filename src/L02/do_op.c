#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4) // Check if exactly 3 arguments are provided
    {
        printf("\n");
        return 0;
    }

    // Convert the first and third arguments to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);

    // Get the operation character
    char operation = argv[2][0];

    // Perform the operation based on the given operator
    switch (operation)
    {
    case '+':
        printf("%d\n", num1 + num2);
        break;
    case '-':
        printf("%d\n", num1 - num2);
        break;
    case '*':
        printf("%d\n", num1 * num2);
        break;
    case '/':
        if (num2 != 0)
            printf("%d\n", num1 / num2);
        else
            printf("Error: Division by zero.\n");
        break;
    case '%':
        if (num2 != 0)
            printf("%d\n", num1 % num2);
        else
            printf("Error: Modulo by zero.\n");
        break;
    default:
        printf("\n");
        break;
    }

    return 0;
}
