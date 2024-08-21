#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
          char *str = argv[1];  // Create a pointer to the string

        while (*str)
        {
            char ch = *str;
            if ((ch < 'z' && ch >= 'a') || (ch < 'Z' && ch >= 'A'))
            {
                ch += 1;
            }
            else if (ch == 'z' || ch == 'Z')
            {
                ch -= 25;
            }
            ft_putchar(ch);
            str++;
        }
    }
    ft_putchar('\n');
    return 0;
}