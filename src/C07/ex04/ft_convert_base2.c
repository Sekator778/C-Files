#include <stdlib.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

// Check if a base is valid: must be at least 2 characters, and no duplicates
int valid_base(char *base)
{
    int i, j;

    if (ft_strlen(base) < 2)
        return (0);
    i = 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

// Find the index of a character in a base string
int index_in_base(char c, char *base)
{
    int i = 0;
    while (base[i])
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

// Convert a string number from base_from to an integer
int ft_atoi_base(char *str, char *base)
{
    int result = 0;
    int sign = 1;
    int base_len = ft_strlen(base);
    int i = 0;

    // Skip whitespaces
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    
    // Handle signs
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }

    // Convert number based on the base
    int idx;
    while ((idx = index_in_base(str[i], base)) != -1)
    {
        result = result * base_len + idx;
        i++;
    }
    return (result * sign);
}

// Convert an integer to a string in a given base
char *ft_itoa_base(int nbr, char *base)
{
    int base_len = ft_strlen(base);
    int sign = nbr < 0 ? -1 : 1;
    int temp_nbr = nbr * sign;
    int len = 0;

    while (temp_nbr > 0)
    {
        temp_nbr /= base_len;
        len++;
    }

    len += (sign == -1) ? 1 : 0; // Reserve space for '-' if negative
    char *result = (char *)malloc(len + 1);
    if (!result)
        return (NULL);

    result[len] = '\0';
    temp_nbr = nbr * sign;
    while (len-- > 0)
    {
        result[len] = base[temp_nbr % base_len];
        temp_nbr /= base_len;
    }
    if (sign == -1)
        result[0] = '-';

    return result;
}
