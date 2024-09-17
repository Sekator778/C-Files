#include "../headers/global.h"

/*
** ft_strlen
** @param s String
** @return length of s
*/

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** ft_strcmp
** @param s1 String 1
** @param s2 String 2
** @return 1 if s1 equal s2 else 0
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = -1;
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	else if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

/*
** ft_strjoin
** @param s1 String 1
** @param s2 String 2
** @return concatenation of s1 and s2
*/

void	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!(res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = 0;
	return (res);
}

/*
** ft_puthex
** @param v long
** @return print v in hexadecimal
*/

void	ft_puthex(long v)
{
	char *base;

	base = "0123456789abcdef";
	if (v > 15)
	{
		ft_puthex(v / 16);
		write(1, &base[v % 16], 1);
	}
	else
	{
		write(1, &base[v % 16], 1);
	}
}

/*
** ft_puthex_filled
** @param v long
** @param width int
** @return print v in hexadecimal left 0 filled
*/

void	ft_puthex_filled(long v, int width)
{
	int i;
	int j;

	i = v;
	j = 0;
	while (i > 15 && ++j)
		i /= 16;
	while (j++ < width)
		write(1, "0", 1);
	ft_puthex(v);
}
