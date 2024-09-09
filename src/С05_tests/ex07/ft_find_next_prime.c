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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

#include <stdio.h>

int ft_is_prime(int nb);
int ft_find_next_prime(int nb);

int main(void)
{
    // Test cases for ft_is_prime
    printf("Is 17 prime? %d\n", ft_is_prime(17)); // Expected: 1
    printf("Is 16 prime? %d\n", ft_is_prime(16)); // Expected: 0
    printf("Is 2 prime? %d\n", ft_is_prime(2));   // Expected: 1
    printf("Is 0 prime? %d\n", ft_is_prime(0));   // Expected: 0
    printf("Is -7 prime? %d\n", ft_is_prime(-7)); // Expected: 0

    // Test cases for ft_find_next_prime
    printf("Next prime after 17: %d\n", ft_find_next_prime(17)); // Expected: 17
    printf("Next prime after 16: %d\n", ft_find_next_prime(16)); // Expected: 17
    printf("Next prime after -5: %d\n", ft_find_next_prime(-5)); // Expected: 2
    printf("Next prime after 0: %d\n", ft_find_next_prime(0));   // Expected: 2
    printf("Next prime after 2147483640: %d\n", ft_find_next_prime(2147483640)); // Large number test

    return 0;
}
