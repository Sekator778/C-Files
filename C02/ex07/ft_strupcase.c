/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:31:34 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/02 18:40:12 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*origin;

	origin = str;
	while (*str)
	{
		if ('a' <= *str && 'z' >= *str)
		{
			*str -= 32;
		}
		str++;
	}
	return (origin);
}
