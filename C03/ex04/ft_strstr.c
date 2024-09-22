/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:40:49 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/04 16:33:54 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*pattern;

	if (!*to_find)
	{
		return (str);
	}
	while (*str)
	{
		start = str;
		pattern = to_find;
		while (*str && *pattern && *str == *pattern)
		{
			str++;
			pattern++;
		}
		if (!*pattern)
		{
			return (start);
		}
		str = start + 1;
	}
	return (0);
}
