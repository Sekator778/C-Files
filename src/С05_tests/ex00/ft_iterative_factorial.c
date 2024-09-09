int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

#include <stdio.h>

int ft_iterative_factorial(int nb);

int main(void)
{
    // Test case 1: Positive number
    printf("Factorial of 5: %d\n", ft_iterative_factorial(5)); // Expected: 120

    // Test case 2: Zero factorial
    printf("Factorial of 0: %d\n", ft_iterative_factorial(0)); // Expected: 1

    // Test case 3: Negative number
    printf("Factorial of -3: %d\n", ft_iterative_factorial(-3)); // Expected: 0

    // Test case 4: Factorial of 1
    printf("Factorial of 1: %d\n", ft_iterative_factorial(1)); // Expected: 1

    return 0;
}
