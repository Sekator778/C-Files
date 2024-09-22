/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:50:35 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/18 17:58:14 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;

	if (length <= 1)
		return (1);
	ascending = 1;
	descending = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			ascending = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			descending = 0;
		i++;
	}
	return (ascending || descending);
}
