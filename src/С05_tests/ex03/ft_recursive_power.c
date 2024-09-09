int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	if (power >= 1)
		return (ft_recursive_power(nb, power -1) * nb);
	return (0);
}
#include <stdio.h>

int ft_recursive_power(int nb, int power);

int main(void)
{
    // Test case 1: Regular positive power
    printf("2^3: %d\n", ft_recursive_power(2, 3)); // Expected: 8

    // Test case 2: Zero power
    printf("5^0: %d\n", ft_recursive_power(5, 0)); // Expected: 1

    // Test case 3: Zero base with positive power
    printf("0^5: %d\n", ft_recursive_power(0, 5)); // Expected: 0

    // Test case 4: Zero base with zero power
    printf("0^0: %d\n", ft_recursive_power(0, 0)); // Expected: 1

    // Test case 5: Negative power
    printf("2^-3: %d\n", ft_recursive_power(2, -3)); // Expected: 0

    return 0;
}
