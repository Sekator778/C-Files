/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:53:50 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/11 15:55:47 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	length;
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	length = max - min;
	range = malloc(length * sizeof(int));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
