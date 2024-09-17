#include "../includes/ft.h"

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_tail(char *str, int size)
{
	int		i;

	i = 0;
	while (++i < size)
		str[i - 1] = str[i];
}
