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

int main()
{
    printf("%d\n", ft_sqrt(25));   // Output: 5
    printf("%d\n", ft_sqrt(0));    // Output: 0
    printf("%d\n", ft_sqrt(1));    // Output: 1
    printf("%d\n", ft_sqrt(-4));   // Output: 0
    printf("%d\n", ft_sqrt(16));   // Output: 4
    printf("%d\n", ft_sqrt(2147395600)); // Output: 46340 (Maximum valid square root)
    return 0;
}

