/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:40:56 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/02 18:42:40 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*origin;

	origin = str;
	while (*str)
	{
		if ('A' <= *str && 'Z' >= *str)
		{
			*str += 32;
		}
		str++;
	}
	return (origin);
}
