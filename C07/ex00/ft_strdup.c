/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:47:36 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/11 15:50:32 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	l;

	l = 0;
	while (src[l])
	{
		l++;
	}
	return (l);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		length;

	if (src == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(src) + 1;
	dest = malloc(sizeof(char) * length);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
