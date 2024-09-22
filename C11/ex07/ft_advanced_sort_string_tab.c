/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:58:55 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/18 15:59:14 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		len;
	int		i;
	char	*str;
	int		k;

	len = 0;
	i = 0;
	while (tab[len])
		len++;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if ((cmp)(tab[i], tab[k]) > 0)
			{
				str = tab[i];
				tab[i] = tab[k];
				tab[k] = str;
			}
			k++;
		}
		i++;
	}
	tab[i] = 0;
}
