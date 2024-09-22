/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:52:01 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/18 15:52:07 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	special_test(char *n1, char *op, char *n2)
{
	int	nb1;
	int	nb2;

	nb1 = ft_atoi(n1);
	nb2 = ft_atoi(n2);
	if (nb1 && nb2 == 0 && get_ope(op) == 2)
	{
		ft_putstr("Stop : division by zero");
		return (1);
	}
	else if (nb1 && nb2 == 0 && get_ope(op) == 4)
	{
		ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

int	get_ope(char *op)
{
	int		i;
	char	*list;

	list = "+-/*%";
	i = -1;
	while (list[++i])
	{
		if (list[i] == op[0] && op[1] == '\0')
			return (i);
	}
	return (-1);
}

void	do_op(char *n1, char *op, char *n2)
{
	int	(*p[5])(int x, int y);
	int	nb1;
	int	nb2;
	int	ope;

	nb2 = ft_atoi(n2);
	ope = get_ope(op);
	nb1 = ft_atoi(n1);
	p[0] = sum;
	p[1] = sub;
	p[2] = div;
	p[3] = mult;
	p[4] = mod;
	if (get_ope(op) == -1)
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return ;
	}
	if (!special_test(n1, op, n2))
		ft_putnbr(p[ope](nb1, nb2));
	ft_putchar('\n');
}
