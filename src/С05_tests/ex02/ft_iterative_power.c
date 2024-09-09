int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main(void)
{
    // Test case 1: Regular positive power
    printf("2^3: %d\n", ft_iterative_power(2, 3)); // Expected: 8

    // Test case 2: Zero power
    printf("5^0: %d\n", ft_iterative_power(5, 0)); // Expected: 1

    // Test case 3: Zero base with positive power
    printf("0^5: %d\n", ft_iterative_power(0, 5)); // Expected: 0

    // Test case 4: Zero base with zero power
    printf("0^0: %d\n", ft_iterative_power(0, 0)); // Expected: 1

    // Test case 5: Negative power
    printf("2^-3: %d\n", ft_iterative_power(2, -3)); // Expected: 0

    // Test case 6: Power of 1
    printf("2^1: %d\n", ft_iterative_power(2, 1)); // Expected: 2

    return 0;
}
