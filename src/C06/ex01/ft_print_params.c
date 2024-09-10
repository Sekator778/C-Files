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
    int i;

    i = 1;
    if (argc != 0 && argv[0])
    {
        while (i < argc)
        {
            ft_print_string(argv[i]);
            ft_print_ch('\n');
            i++;
        }
    }
    return (0);
}