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
            int i = 0;
        while (argv[1][i])
        {
            char ch = argv[1][i];
            if ((ch < 'z' && ch >= 'a') || (ch < 'Z' && ch >= 'A'))
            {
                ch += 1;
            }
            else if (ch == 'z' || ch == 'Z')
            {
                ch -= 25;
            }
            ft_putchar(ch);
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}