#include <unistd.h>

void ft_print_ch(char c)
{
    write(1, &c, 1);
}

void ft_print_string(char str[])
{
    int i;

    i = 0;

    while (str[i])
    {
        ft_print_ch(str[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    char *program_name;
    
    int i;

    if (argc > 0)
    {
        program_name = argv[0];
        i = 0;
        while (argv[0][i])
        {
            if (argv[0][i] == '\\' || argv[0][i] == '/')
            {
                program_name = &argv[0][i + 1]; // check here
            }
            i++;
        }
        ft_print_string(program_name);
    }
    ft_print_ch('\n');
    return (0);
}