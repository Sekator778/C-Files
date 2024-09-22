/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onikolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:19:02 by onikolai          #+#    #+#             */
/*   Updated: 2024/09/11 18:31:19 by onikolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset) && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (is_separator(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*ft_strndup(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		start;
	int		word_count;
	char	**result;
	int		word_index;

	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	word_index = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
		{
			start = i;
			while (str[i] != '\0' && !is_separator(str[i], charset))
				i++;
			result[word_index++] = ft_strndup(str, start, i);
		}
		i++;
	}
	result[word_index] = NULL;
	return (result);
}
