/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:50:45 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/11 17:36:05 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
	{
		return (0);
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
		{
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	return (i);
}

int	get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = sign * -1;
		}
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;
	int	i;
	int	idx;

	result = 0;
	base_len = ft_strlen(base);
	i = skip_whitespace(str);
	sign = get_sign(str, &i);
	idx = index_in_base(str[i], base);
	while (idx != -1)
	{
		result = result * base_len + idx;
		i++;
		idx = index_in_base(str[i], base);
	}
	return (result * sign);
}
