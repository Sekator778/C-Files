#include <unistd.h>

int get_repeat_count(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 1;
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 1;
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i])
        {
            char ch = argv[1][i];
            int repeatCount = get_repeat_count(ch);
            while(repeatCount > 0)
            {
                write(1, &ch, 1);
                repeatCount--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
