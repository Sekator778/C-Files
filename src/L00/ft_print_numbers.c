#include <unistd.h>

void main(void) 
{
    char ch = '0';
    while (ch <= '9')
    {
        write(1, &ch, 1);
        ch++;
    }
}