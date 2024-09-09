int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return (index);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
#include <stdio.h>

int ft_fibonacci(int index);

int main(void)
{
    // Test case 1: Fibonacci of 0
    printf("Fibonacci of 0: %d\n", ft_fibonacci(0)); // Expected: 0

    // Test case 2: Fibonacci of 1
    printf("Fibonacci of 1: %d\n", ft_fibonacci(1)); // Expected: 1

    // Test case 3: Fibonacci of 5
    printf("Fibonacci of 5: %d\n", ft_fibonacci(5)); // Expected: 5

    // Test case 4: Fibonacci of 10
    printf("Fibonacci of 10: %d\n", ft_fibonacci(10)); // Expected: 55

    // Test case 5: Negative index
    printf("Fibonacci of -5: %d\n", ft_fibonacci(-5)); // Expected: -1

    return 0;
}
