#include "dict.h"
#include "utils.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

static int parse_line(char *line, char **number_part, char **word_part);
static t_dict *parse_dict_entries(char *dict_content);

t_dict *parse_dict(char *dict_file)
{
	int fd;
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;
	char *dict_content;
	int total_size;
	t_dict *dict;

	fd = open(dict_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	dict_content = malloc(1);
	if (!dict_content)
		return (NULL);
	dict_content[0] = '\0';
	total_size = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		total_size += bytes_read;
		char *new_content = malloc(total_size + 1);
		if (!new_content)
			return (NULL);
		ft_strcpy(new_content, dict_content);
		ft_strcat(new_content, buffer);
		free(dict_content);
		dict_content = new_content;
	}
	close(fd);
	if (bytes_read == -1)
	{
		free(dict_content);
		return (NULL);
	}
	dict = parse_dict_entries(dict_content);
	free(dict_content);
	return (dict);
}

static t_dict *parse_dict_entries(char *dict_content)
{
	t_dict *dict;
	char **lines;
	int line_count;
	int i;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	lines = ft_split_lines(dict_content, &line_count);
	if (!lines)
	{
		free(dict);
		return (NULL);
	}
	dict->entries = malloc(sizeof(t_dict_entry) * line_count);
	if (!dict->entries)
	{
		free_dict(dict);
		free(lines);
		return (NULL);
	}
	dict->size = 0;
	i = 0;
	while (i < line_count)
	{
		char *number_part;
		char *word_part;
		if (parse_line(lines[i], &number_part, &word_part) == -1)
		{
			int k = 0;
			while (k < i)
			{
				free(dict->entries[k].number);
				free(dict->entries[k].word);
				k++;
			}
			free_dict(dict);
			while (i >= 0)
				free(lines[i--]);
			free(lines);
			return (NULL);
		}
		dict->entries[dict->size].number = number_part;
		dict->entries[dict->size].word = word_part;
		dict->size++;
		i++;
	}
	i = 0;
	while (i < line_count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (dict);
}

static int parse_line(char *line, char **number_part, char **word_part)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j] >= '0' && line[j] <= '9')
		j++;
	if (j == i)
		return (-1);
	*number_part = ft_strndup(&line[i], j - i);
	if (!*number_part)
		return (-1);
	i = j;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != ':')
	{
		free(*number_part);
		return (-1);
	}
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	*word_part = ft_strdup(&line[i]);
	if (!*word_part)
	{
		free(*number_part);
		return (-1);
	}
	tmp = ft_trim(*number_part);
	free(*number_part);
	*number_part = tmp;
	tmp = ft_trim(*word_part);
	free(*word_part);
	*word_part = tmp;
	if (!*number_part || !*word_part)
		return (-1);
	return (0);
}

void free_dict(t_dict *dict)
{
	int i;

	if (!dict)
		return;
	i = 0;
	while (i < dict->size)
	{
		if (dict->entries[i].number)
			free(dict->entries[i].number);
		if (dict->entries[i].word)
			free(dict->entries[i].word);
		i++;
	}
	free(dict->entries);
	free(dict);
}
