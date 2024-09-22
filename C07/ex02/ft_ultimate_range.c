/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:20 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/11 16:05:31 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	length = max - min;
	*range = malloc(length * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < length)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (length);
}
