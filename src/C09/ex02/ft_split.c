#include <stdlib.h>

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		if (str[i] && !ft_is_separator(str[i], charset))
		{
			count++;
			while (str[i] && !ft_is_separator(str[i], charset))
				i++;
		}
	}
	return (count);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;
	int		start;
	int		word_index;

	arr = (char **)malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		start = i;
		while (str[i] && !ft_is_separator(str[i], charset))
			i++;
		if (i > start)
		{
			arr[word_index] = ft_strndup(str + start, i - start);
			word_index++;
		}
	}
	arr[word_index] = 0;
	return (arr);
}

#include <stdio.h>

int	main(void)
{
	char **result = ft_split("Hello, world;42 is amazing!", ",; ");
	for (int i = 0; result[i]; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}
