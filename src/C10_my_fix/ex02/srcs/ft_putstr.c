#include "../includes/ft.h"

void	ft_putstr_buf(char *str, int len)
{
	int	i;
	i = 0;
	while (i < len)
		ft_putchar((*(str + i++)), 1);
}

void	ft_putstr(char *str, int out)
{
	while (*str)
		write(out, str++, 1);
}

void	ft_putstr_headfile(char *filepath)
{
	ft_putstr("==> ", 1);
	ft_putstr(filepath, 1);
	ft_putstr(" <==\n", 1);
}
