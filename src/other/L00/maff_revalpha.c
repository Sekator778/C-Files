#include <unistd.h>

void ft_putchar(char ch)
{
    write(1, &ch, 1);
}

int main(void)
{
    int i = 90;

    while (i >= 65)
    {
        (i % 2 != 0) ? ft_putchar(i) : ft_putchar(i + 32);
        i--;
    }
    ft_putchar('\n');

    return 0;
}
