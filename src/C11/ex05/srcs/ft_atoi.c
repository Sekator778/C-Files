#include "../includes/ft.h"

int	ft_atoi(char *str)
{
    int nb;
    int sign;

    nb = 0;
    sign = 1;
    while (*str == ' ' || *str == '\t')
    {
        str++;
    }
    while (*str == '-' || *str == '+')
    {
        if(*str == '-')
        {
        sign *= -1;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        nb = (nb * 10) + (*str - '0');
        str++;
    }
    return (sign * nb);
}
