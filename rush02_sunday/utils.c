#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putendl(char *str)
{
    ft_putstr(str);
    ft_putchar('\n');
}

char *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *dup = malloc(len + 1);
    int i = 0;
    if (!dup)
        return (NULL);
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    *ft_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

char *ft_strndup(char *src, int n)
{
    char *dup = malloc(n + 1);
    int i = 0;
    if (!dup)
        return (NULL);
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
    int start = 0;
    int end = ft_strlen(str) - 1;
    char *trimmed;
    int i;

    while (ft_isspace(str[start]) && str[start])
        start++;
    while (ft_isspace(str[end]) && end > start)
        end--;
    trimmed = malloc(end - start + 2);
    if (!trimmed)
        return (NULL);
    i = 0;
    while (start <= end)
    {
        trimmed[i] = str[start];
        i++;
        start++;
    }
    trimmed[i] = '\0';
    return (trimmed);
}

int ft_is_valid_number(char *str)
{
    int i = 0;
    int sign = 1;

    while (ft_isspace(str[i]))
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    if (!ft_isdigit(str[i]))
        return (0);
    while (ft_isdigit(str[i]))
        i++;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] != '\0')
        return (0);
    if (sign == -1)
        return (0);
    return (1);
}

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int ft_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

char **ft_split_lines(char *str, int *line_count)
{
    int i = 0;
    int count = 0;
    char **lines;
    int start = 0;
    int line_index = 0;

    while (str[i])
    {
        if (str[i] == '\n')
            count++;
        i++;
    }
    lines = malloc(sizeof(char *) * (count + 2));
    if (!lines)
        return (NULL);
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
        {
            lines[line_index++] = ft_strndup(&str[start], i - start);
            start = i + 1;
        }
        i++;
    }
    if (start < i)
        lines[line_index++] = ft_strndup(&str[start], i - start);
    lines[line_index] = NULL;
    *line_count = line_index;
    return (lines);
}
