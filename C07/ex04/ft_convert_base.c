/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:43:00 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/11 16:46:08 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		valid_base(char *base);
int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);
char	*ft_itoa_base(int nbr, char *base);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	calc_len(int nbr, int base_len, int sign)
{
	int	len;
	int	temp_nbr;

	len = 0;
	temp_nbr = nbr * sign;
	if (nbr == 0)
	{
		len = 1;
	}
	while (temp_nbr > 0)
	{
		temp_nbr = temp_nbr / base_len;
		len++;
	}
	if (sign == -1)
	{
		len++;
	}
	return (len);
}

char	*create_base_str(int nbr, int sign, int len, char *base)
{
	int		base_len;
	char	*result;
	int		temp_nbr;

	base_len = ft_strlen(base);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	temp_nbr = nbr * sign;
	while (len-- > 0)
	{
		result[len] = base[temp_nbr % base_len];
		temp_nbr = temp_nbr / base_len;
	}
	if (sign == -1)
	{
		result[0] = '-';
	}
	return (result);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		base_len;
	int		sign;
	int		len;

	base_len = ft_strlen(base);
	sign = 1;
	if (nbr < 0)
	{
		sign = -1;
	}
	len = calc_len(nbr, base_len, sign);
	return (create_base_str(nbr, sign, len, base));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	number;

	if (!valid_base(base_from) || !valid_base(base_to))
	{
		return (NULL);
	}
	number = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(number, base_to));
}
