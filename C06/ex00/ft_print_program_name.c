/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:15:56 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/10 14:46:10 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_ch(char c)
{
	write(1, &c, 1);
}

void	ft_print_string(char str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_print_ch(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 0)
		ft_print_string(argv[0]);
	ft_print_ch('\n');
	return (0);
}
