#include <unistd.h>

void ft_putchar(char ch)
{
    write(1, &ch, 1);
}

int rot13(char c)
{
    if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
        c += 13;
    else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
        c -= 13;
    return (c);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i])
        {
            char ch = argv[1][i];
            ch = rot13(ch);
            ft_putchar(ch);
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}
