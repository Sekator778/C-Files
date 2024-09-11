#include <stdlib.h>

int valid_base(char *base);
int ft_atoi_base(char *str, char *base);
char *ft_itoa_base(int nbr, char *base);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    if (!valid_base(base_from) || !valid_base(base_to))
        return (NULL);

    int number = ft_atoi_base(nbr, base_from);
    return ft_itoa_base(number, base_to);
}

// Example usage in main
#include <stdio.h>

int main(void)
{
    char *result = ft_convert_base("1010", "01", "0123456789");
    if (result)
    {
        printf("%s\n", result); // Output: "10"
        free(result);
    }
    return 0;
}
