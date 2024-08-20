#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        char *str = argv[1];
        char ch1 = argv[2][0];
        char ch2 = argv[3][0];
        int i = 0;

        while (str[i])
        {
            if (str[i] == ch1)
            {
                str[i] = ch2;
            }
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}