#include "unistd.h"

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i] != '\0')
        {
            char ch = argv[1][i];
            if (ch >= 'a' && ch <= 'z') 
            {
                ch-=32;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch+=32;
            }
                write(1, &ch, 1);
           i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
