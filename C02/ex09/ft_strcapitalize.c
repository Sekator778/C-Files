/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:43:33 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/03 15:08:12 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

void	capitalize_word(char *str, int *i)
{
	if (str[*i] >= 'a' && str[*i] <= 'z')
		str[*i] -= 32;
	(*i)++;
	while (str[*i] && is_alphanumeric(str[*i]))
	{
		if (str[*i] >= 'A' && str[*i] <= 'Z')
			str[*i] += 32;
		(*i)++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (new_word && is_alphanumeric(str[i]))
			capitalize_word(str, &i);
		else
		{
			new_word = !is_alphanumeric(str[i]);
			i++;
		}
	}
	return (str);
}
