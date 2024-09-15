#include "dict.h"
#include "utils.h"
#include <stdio.h>

int main(void)
{
    char *dict_file = "numbers.dict";
    t_dict *dict = parse_dict(dict_file);

    if (!dict)
    {
        ft_putstr("Error: Could not parse dictionary.\n");
        return 1;
    }

    for (int i = 0; i < dict->size; i++)
    {
        ft_putstr(dict->entries[i].number);
        ft_putstr(": ");
        ft_putstr(dict->entries[i].word);
        ft_putstr("\n");
    }

    free_dict(dict);
    return 0;
}
