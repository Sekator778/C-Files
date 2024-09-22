#include <unistd.h>

int main(int argc, char *argv[])
{
    int checkBoxS[256] = {0}; // Array to track characters in the second string

    if (argc == 3)
    {
        char *s1 = argv[1];
        char *s2 = argv[2];
        int i;

        // Mark characters that appear in the second string
        while (*s2)
        {
            checkBoxS[(unsigned char)*s2] = 1; //mark 1 if the char present in s2
            s2++;
        }

        // Check each character in the first string
        while (*s1)
        {
            if (checkBoxS[(unsigned char)*s1] == 1 && checkBoxS[(unsigned char)*s1] != 2)
            {
                write(1, s1, 1);
                checkBoxS[(unsigned char)*s1] = 2; // Mark as printed -- duplicate s1
            }
            s1++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
