#include <unistd.h>

char shiftChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return 'z' - (ch - 'a');
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        return 'Z' - (ch - 'A');
    }
    return ch; // If not an alphabetic character, return the original character
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *str = argv[1];
        while (*str)
        {
            char ch = shiftChar(*str);
            write(1, &ch, 1);
            str++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
