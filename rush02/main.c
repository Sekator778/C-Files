#include "dict.h"
#include "utils.h"

int convert_number_to_words(char *number_str, t_dict *dict);

int main(int argc, char **argv)
{
    char    *dict_file;
    char    *number_str;
    t_dict  *dict;

    dict_file = "numbers.dict";
    if (argc == 2)
        number_str = argv[1];
    else if (argc == 3)
    {
        dict_file = argv[1];
        number_str = argv[2];
    }
    else
    {
        ft_putendl("Error");
        return (1);
    }
    if (!ft_is_valid_number(number_str))
    {
        ft_putendl("Error");
        return (1);
    }
    dict = parse_dict(dict_file);
    if (!dict)
    {
        ft_putendl("Dict Error");
        return (1);
    }
    if (convert_number_to_words(number_str, dict) == -1)
    {
        ft_putendl("Dict Error");
        free_dict(dict);
        return (1);
    }
    free_dict(dict);
    return (0);
}
