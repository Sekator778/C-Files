#include <unistd.h>

int main()
{
    char ch = '9';
    while (ch >= '0')
    {
        write(1, &ch, 1);
        ch--;
    }
    write(1, "\n", 1);

    return 0;
}