// ft_putchar.c
#include <unistd.h>
#include "ft_putchar.h"

void ft_putchr(char ch)
{
    write(1, &ch, 1);
}
