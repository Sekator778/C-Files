#include <stdio.h>

int	ft_strlen(char *str)
{
    int i = 0;
    while (str[i++]) ;
    return i-1;
}
