#include <unistd.h>

void union_strings(char *s1, char *s2)
{
    char checkBox[256] = {0}; // Array to track characters

    // Process the first string
    int i = 0;
    while (s1[i])
    {
        if (checkBox[(unsigned char)s1[i]] == 0)
        {
            write(1, &s1[i], 1); // Output the character
            checkBox[(unsigned char)s1[i]] = 1; // Mark the character as seen
        }
        i++;
    }

    // Process the second string
    i = 0;
    while (s2[i])
    {
        if (checkBox[(unsigned char)s2[i]] == 0)
        {
            write(1, &s2[i], 1); // Output the character
            checkBox[(unsigned char)s2[i]] = 1; // Mark the character as seen
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 3) // Ensure there are exactly two arguments
    {
        union_strings(argv[1], argv[2]);
    }
    write(1, "\n", 1); // Output a newline
    return 0;
}
