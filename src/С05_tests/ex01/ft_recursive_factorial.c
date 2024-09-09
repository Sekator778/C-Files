int ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    return (nb * ft_recursive_factorial(nb - 1));
}
#include <stdio.h>

int ft_recursive_factorial(int nb);

int main(void)
{
    // Test case 1: Positive number
    printf("Recursive factorial of 5: %d\n", ft_recursive_factorial(5)); // Expected: 120

    // Test case 2: Zero factorial
    printf("Recursive factorial of 0: %d\n", ft_recursive_factorial(0)); // Expected: 1

    // Test case 3: Negative number
    printf("Recursive factorial of -3: %d\n", ft_recursive_factorial(-3)); // Expected: 0

    // Test case 4: Factorial of 1
    printf("Recursive factorial of 1: %d\n", ft_recursive_factorial(1)); // Expected: 1

    return 0;
}
