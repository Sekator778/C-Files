#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char *ft_strdup(char *src)
{
	int len;
	char *dup;

	len = ft_strlen(src);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

char *ft_strndup(char *src, int n)
{
	int i;
	char *dup;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_trim(char *str)
{
	int start;
	int end;
	int len;
	char *trimmed;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
		start++;
	while ((str[end] == ' ' || str[end] == '\t' || str[end] == '\n') && end >= start)
		end--;
	len = end - start + 1;
	trimmed = ft_strndup(&str[start], len);
	return (trimmed);
}

char **ft_split_lines(char *str, int *line_count)
{
	int i;
	int lines;
	int len;
	int start;
	int line_idx;
	char **result;

	i = 0;
	lines = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '\n')
			lines++;
		i++;
	}
	if (str[len - 1] != '\n')
		lines++;

	result = malloc(sizeof(char *) * (lines + 1));
	if (!result)
		return (NULL);

	start = 0;
	line_idx = 0;
	i = 0;
	while (i <= len)
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			int line_len = i - start;
			result[line_idx] = ft_strndup(&str[start], line_len);
			if (!result[line_idx])
			{
				int k = 0;
				while (k < line_idx)
				{
					free(result[k]);
					k++;
				}
				free(result);
				return (NULL);
			}
			line_idx++;
			start = i + 1;
		}
		i++;
	}

	result[line_idx] = NULL;
	*line_count = lines;
	return (result);
}
