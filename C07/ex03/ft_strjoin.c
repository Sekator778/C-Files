/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:50 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/11 16:12:38 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_combsize(int size, char **strs, char *sep)
{
	int	i;
	int	combsize;

	i = 0;
	combsize = 0;
	while (i < size)
	{
		combsize += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		combsize += ft_strlen(sep) * (size - 1);
	return (combsize);
}

char	*ft_strcat(char *dest, char *src)
{
	int	idest;
	int	isrc;

	idest = ft_strlen(dest);
	isrc = 0;
	while (src[isrc] != '\0')
	{
		dest[idest + isrc] = src[isrc];
		isrc++;
	}
	dest[idest + isrc] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		combsize;
	char	*dest;
	int		i;

	if (size == 0)
	{
		dest = malloc(1);
		if (dest)
			dest[0] = '\0';
		return (dest);
	}
	combsize = ft_combsize(size, strs, sep);
	dest = malloc(sizeof(char) * (combsize + 1));
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]); 
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest); 
}
