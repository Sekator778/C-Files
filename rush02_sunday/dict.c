#include "dict.h"
#include "utils.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

static int parse_line(char *line, char **number_part, char **word_part);
static t_dict *parse_dict_entries(char *dict_content);
static char *merge_buffers(char *dict_content, char *buffer, int bytes_read, int *total_size);

t_dict *parse_dict(char *dict_file)
{
    int fd;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    char *dict_content;
    int total_size;
    t_dict *dict;

    total_size = 0;
    dict_content = malloc(1);
    if (!dict_content)
        return (NULL);
    dict_content[0] = '\0';
    fd = open(dict_file, O_RDONLY);
    if (fd == -1)
    {
        free(dict_content);
        return (NULL);
    }
    do
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0)
        {
            dict_content = merge_buffers(dict_content, buffer, bytes_read, &total_size);
            if (!dict_content)
            {
                close(fd);
                return (NULL);
            }
        }
    } while (bytes_read > 0);
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

static char *merge_buffers(char *dict_content, char *buffer, int bytes_read, int *total_size)
{
    char *new_content;
    int old_len;
    int i, j;

    buffer[bytes_read] = '\0';
    *total_size += bytes_read;
    new_content = malloc(*total_size + 1);
    if (!new_content)
    {
        free(dict_content);
        return (NULL);
    }
    old_len = ft_strlen(dict_content);
    i = 0;
    while (i < old_len)
    {
        new_content[i] = dict_content[i];
        i++;
    }
    j = 0;
    while (buffer[j])
    {
        new_content[i + j] = buffer[j];
        j++;
    }
    new_content[i + j] = '\0';
    free(dict_content);
    return (new_content);
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
        free(lines);
        free(dict);
        return (NULL);
    }
    dict->size = 0;
    i = 0;
    while (i < line_count)
    {
        if (parse_line(lines[i], &dict->entries[dict->size].number, &dict->entries[dict->size].word) == -1)
        {
            free(lines);
            free_dict(dict);
            return (NULL);
        }
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
    int i, j;
    char *temp_number;

    i = 0;
    while (ft_isspace(line[i]))
        i++;
    j = i;
    while (line[j] && line[j] != ':' && !ft_isspace(line[j]))
        j++;
    temp_number = ft_strndup(&line[i], j - i);
    if (!temp_number || !ft_is_valid_number(temp_number))
    {
        free(temp_number);
        return (-1);
    }
    *number_part = ft_trim(temp_number);
    free(temp_number);
    if (!*number_part)
        return (-1);
    i = j;
    while (line[i] && ft_isspace(line[i]))
        i++;
    if (line[i] != ':')
        return (-1);
    i++;
    while (line[i] && ft_isspace(line[i]))
        i++;
    *word_part = ft_trim(&line[i]);
    if (!*word_part)
        return (-1);
    return (0);
}

char *lookup_word(t_dict *dict, char *number)
{
    int i;

    i = 0;
    while (i < dict->size)
    {
        if (ft_strcmp(dict->entries[i].number, number) == 0)
            return (dict->entries[i].word);
        i++;
    }
    return (NULL);
}

void free_dict(t_dict *dict)
{
    int i;

    if (dict)
    {
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
}