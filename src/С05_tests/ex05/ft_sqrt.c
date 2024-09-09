int ft_sqrt(int nb)
{
    int i;

    if (nb < 0)
        return (0);
    i = 0;
    while (i * i <= nb && i <= 46340)
    {
        if (i * i == nb)
            return (i);
        i++;
    }
    return (0);
}
#include <stdio.h>

int ft_sqrt(int nb);

int main(void)
{
    // Test case 1: Perfect square
    printf("Square root of 16: %d\n", ft_sqrt(16)); // Expected: 4

    // Test case 2: Not a perfect square
    printf("Square root of 15: %d\n", ft_sqrt(15)); // Expected: 0

    // Test case 3: Large perfect square
    printf("Square root of 2147395600: %d\n", ft_sqrt(2147395600)); // Expected: 46340

    // Test case 4: Negative input
    printf("Square root of -4: %d\n", ft_sqrt(-4)); // Expected: 0

    // Test case 5: Zero input
    printf("Square root of 0: %d\n", ft_sqrt(0)); // Expected: 0

    return 0;
}
