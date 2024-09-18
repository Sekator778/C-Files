#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		main(int ac, char **av);
int		sum(int a, int b);
int		sub(int a, int b);
int		mult(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
void	do_op(char *n1, char *op, char *n2);
int		get_ope(char *op);

#endif