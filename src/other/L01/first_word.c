#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)  // Check if exactly one argument is provided
    {
        // Skip leading spaces and tabs
        while (argv[1][i] &&(argv[1][i] == ' ' || argv[1][i] == '\t'))
            i++;

        // Print the first word
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
        {
            ft_putchar(argv[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}
