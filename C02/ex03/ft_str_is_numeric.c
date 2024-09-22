/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:20:40 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/02 18:23:50 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && '9' >= *str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
