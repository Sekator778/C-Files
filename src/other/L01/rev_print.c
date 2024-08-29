#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int length(char *str)
{
    int length = 0;
    while (str[length])
    {
        length++;
    }
    return length;
}

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        int l = length(argv[1]);
        for (int i = l-1; i >= 0; i--)
        {
            ft_putchar(argv[1][i]);
        }
        
    }
    ft_putchar('\n');
    return 0;
}