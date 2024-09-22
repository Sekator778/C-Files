/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:43:21 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/03 17:43:26 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned long num, int digits)
{
	char	hex[16];
	char	*hex_chars;
	int		i;

	hex_chars = "0123456789abcdef";
	i = 0;
	while (i < digits)
	{
		hex[digits - 1 - i] = hex_chars[num % 16];
		num /= 16;
		i++;
	}
	write(1, hex, digits);
}

void	print_memory_line(unsigned char *ptr, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (j < size)
			print_hex(ptr[j], 2);
		else
			write(1, "  ", 2);
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
	j = 0;
	while (j < 16 && j < size)
	{
		if (ptr[j] >= 32 && ptr[j] <= 126)
			ft_putchar(ptr[j]);
		else
			ft_putchar('.');
		j++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	line_size;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex((unsigned long)(ptr + i), 16);
		write(1, ": ", 2);
		line_size = 16;
		if (size - i < 16)
			line_size = size - i;
		print_memory_line(ptr + i, line_size);
		i += 16;
	}
	return (addr);
}
