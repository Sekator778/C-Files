#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char *s1 = argv[1];
        char *s2 = argv[2];
        int i = 0;
        int j = 0;

        while (s1[i])
        {
            while (s2[j])
            {
                if (s2[j] == s1[i])
                {
                    break;
                }
                j++;
            }
            if (!s2[j])
            {
                write(1, "\n", 1);
                return 0;
            }
            i++;
            j++;
        }

        // If all characters in s1 were found in s2, print s1
        write(1, s1, i);
    }
    write(1, "\n", 1);
    return 0;
}