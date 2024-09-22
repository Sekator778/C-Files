/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:23:40 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/05 16:42:14 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || 
		*str == '\r' || *str == '\v' || *str == '\f')
	{
		str++;
	}
	return (str);
}

int	handle_sign(char **str)
{
	int	sign;

	sign = 1;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[i] || !base[i + 1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || 
			base[i] == '\t' || base[i] == '\n' || base[i] == '\r' || 
			base[i] == '\v' || base[i] == '\f')
			return (0);
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

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	result;
	int	sign;
	int	index;

	if (!is_valid_base(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	str = skip_whitespace(str);
	sign = handle_sign(&str);
	result = 0;
	index = find_in_base(*str, base);
	while (index != -1)
	{
		result = result * base_len + index;
		str++;
		index = find_in_base(*str, base);
	}
	return (result * sign);
}
