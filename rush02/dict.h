#ifndef DICT_H
#define DICT_H

typedef struct s_dict_entry
{
    char *number;
    char *word;
} t_dict_entry;

typedef struct s_dict
{
    t_dict_entry *entries;
    int size;
} t_dict;

t_dict *parse_dict(char *dict_file);

char *lookup_word(t_dict *dict, char *number);

void free_dict(t_dict *dict);

#endif
