/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:57:58 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/18 15:58:16 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		k;
	char	*str;
	int		len;

	len = 0;
	i = 0;
	while (tab[len])
		len++;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (ft_strcmp(tab[i], tab[k]) > 0)
			{
				str = tab[i];
				tab[i] = tab[k];
				tab[k] = str;
			}
			k++;
		}
		i++;
	}
	tab[i] = NULL;
}
