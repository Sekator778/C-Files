#include "dict.h"
#include "utils.h"
#include <stdlib.h>

static int	handle_zero(t_dict *dict);
static int	handle_scale(int scale_index, t_dict *dict);
static int	process_group(char *group, int group_len, t_dict *dict);
static int	process_hundreds(char *group, t_dict *dict);
static int	process_tens(char *group, t_dict *dict);
static int	process_units(char *group, t_dict *dict);

static int process_group_and_scale(char *group, int group_len, int len, int i, t_dict *dict)
{
    if (group[0] != '0' || (group_len > 1 && group[1] != '0') || (group_len > 2 && group[2] != '0'))
    {
        if (process_group(group, group_len, dict) == -1)
            return (-1);
        if (handle_scale((len - i - group_len) / 3, dict) == -1)
            return (-1);
        if (i + group_len < len)
            ft_putchar(' ');
    }
    return (0);
}

int convert_number_to_words(char *number_str, t_dict *dict)
{
    int len;
    int i;
    int first_group_digits;
    int group_len;
    char group[4];

    if (ft_strcmp(number_str, "0") == 0)
        return (handle_zero(dict));

    len = ft_strlen(number_str);
    first_group_digits = len % 3;
    if (first_group_digits == 0)
        first_group_digits = 3;

    i = 0;
    while (i < len)
    {
        group_len = (i == 0) ? first_group_digits : 3;
        ft_strncpy(group, &number_str[i], group_len);
        group[group_len] = '\0';
        if (process_group_and_scale(group, group_len, len, i, dict) == -1)
            return (-1);
        i += group_len;
    }
    ft_putchar('\n');
    return (0);
}

static int	handle_zero(t_dict *dict)
{
	char	*word;

	word = lookup_word(dict, "0");
	if (word)
	{
		ft_putstr(word);
		ft_putchar('\n');
		return (0);
	}
	else
	{
		ft_putendl("Dict Error");
		return (-1);
	}
}

static int	handle_scale(int scale_index, t_dict *dict)
{
	char	scale_number[40];
	char	*scale_word;
	int		j;

	if (scale_index <= 0)
		return (0);
	scale_number[0] = '1';
	j = 1;
	while (j <= scale_index * 3)
	{
		scale_number[j] = '0';
		j++;
	}
	scale_number[j] = '\0';
	scale_word = lookup_word(dict, scale_number);
	if (scale_word)
	{
		ft_putchar(' ');
		ft_putstr(scale_word);
		return (0);
	}
	else
		return (-1);
}

static int	process_group(char *group, int group_len, t_dict *dict)
{
	if (group_len == 3)
	{
		if (process_hundreds(group, dict) == -1)
			return (-1);
		group += 1;
		group_len -= 1;
	}
	if (group_len == 2)
	{
		if (process_tens(group, dict) == -1)
			return (-1);
	}
	else if (group_len == 1)
	{
		if (process_units(group, dict) == -1)
			return (-1);
	}
	return (0);
}

static int	process_hundreds(char *group, t_dict *dict)
{
	char	hundred[2];
	char	*word;

	if (group[0] != '0')
	{
		hundred[0] = group[0];
		hundred[1] = '\0';
		word = lookup_word(dict, hundred);
		if (word)
		{
			ft_putstr(word);
			ft_putchar(' ');
			word = lookup_word(dict, "100");
			if (!word)
				return (-1);
			ft_putstr(word);
			if (group[1] != '0' || group[2] != '0')
				ft_putchar(' ');
		}
		else
			return (-1);
	}
	return (0);
}

static int	process_tens(char *group, t_dict *dict)
{
	char	*word;

	if (group[0] == '1')
	{
		char	teen[3];

		teen[0] = group[0];
		teen[1] = group[1];
		teen[2] = '\0';
		word = lookup_word(dict, teen);
		if (word)
		{
			ft_putstr(word);
			return (0);
		}
		else
			return (-1);
	}
	else if (group[0] != '0')
	{
		char	tens[3];

		tens[0] = group[0];
		tens[1] = '0';
		tens[2] = '\0';
		word = lookup_word(dict, tens);
		if (word)
		{
			ft_putstr(word);
			if (group[1] != '0')
				ft_putchar(' ');
		}
		else
			return (-1);
	}
	return (process_units(&group[1], dict));
}

static int	process_units(char *group, t_dict *dict)
{
	char	unit[2];
	char	*word;

	if (group[0] != '0')
	{
		unit[0] = group[0];
		unit[1] = '\0';
		word = lookup_word(dict, unit);
		if (word)
		{
			ft_putstr(word);
			return (0);
		}
		else
			return (-1);
	}
	return (0);
}
