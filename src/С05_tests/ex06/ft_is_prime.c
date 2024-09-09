int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}
#include <stdio.h>

int ft_is_prime(int nb);

int main(void)
{
    // Test case 1: Prime number
    printf("Is 17 prime? %d\n", ft_is_prime(17)); // Expected: 1 (true)

    // Test case 2: Non-prime number
    printf("Is 16 prime? %d\n", ft_is_prime(16)); // Expected: 0 (false)

    // Test case 3: Prime number
    printf("Is 2 prime? %d\n", ft_is_prime(2)); // Expected: 1 (true)

    // Test case 4: Non-prime number (less than 2)
    printf("Is 0 prime? %d\n", ft_is_prime(0)); // Expected: 0 (false)

    // Test case 5: Large prime number
    printf("Is 2147483647 prime? %d\n", ft_is_prime(2147483647)); // Expected: 1 (true)

    // Test case 6: Negative number
    printf("Is -7 prime? %d\n", ft_is_prime(-7)); // Expected: 0 (false)

    return 0;
}
