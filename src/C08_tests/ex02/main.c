#include <stdio.h>
#include "ft_abs.h"

int main()
{
    int val1 = -42;
    int val2 = 42;
    int val3 = 0;
    int val4 = -100;
    
    // Basic tests
    printf("ABS(%d) = %d\n", val1, ABS(val1)); // Expecting 42
    printf("ABS(%d) = %d\n", val2, ABS(val2)); // Expecting 42
    printf("ABS(%d) = %d\n", val3, ABS(val3)); // Expecting 0
    printf("ABS(%d) = %d\n", val4, ABS(val4)); // Expecting 100

    // Complex expression tests
    printf("ABS(%d + %d) = %d\n", val1, 2, ABS(val1 + 2)); // Expecting 40
    printf("ABS(%d - %d) = %d\n", val2, 84, ABS(val2 - 84)); // Expecting 42

    // Test with multiplication and division
    printf("ABS(%d * %d) = %d\n", val1, -1, ABS(val1 * -1)); // Expecting 42
    printf("ABS(%d / %d) = %d\n", val1, 2, ABS(val1 / 2));   // Expecting 21

    return 0;
}
