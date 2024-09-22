/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:45:02 by onikolai          #+#    #+#             */
/*   Updated: 2024/08/29 14:55:22 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(int num)
{
	char	digits[2];

	digits[0] = '0' + num / 10;
	digits[1] = '0' + num % 10;
	write(1, digits, 2);
}

void	ft_print_combination(int num1, int num2)
{
	ft_print_number(num1);
	write(1, " ", 1);
	ft_print_number(num2);
	if (num1 != 98 || num2 != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			ft_print_combination(num1, num2);
			num2++;
		}
		num1++;
	}
}
