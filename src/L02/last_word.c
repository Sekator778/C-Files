#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *s = argv[1];
        int i = 0;

        // Find the end of the string
        while (s[i])
            i++;
        
        // Move backward to skip trailing spaces/tabs
        while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t'))
            i--;
        
        // Find the start of the last word
        int end = i;
        while (i > 0 && s[i - 1] != ' ' && s[i - 1] != '\t')
            i--;

        // Print the last word
        write(1, &s[i], end - i);
    }
    write(1, "\n", 1);
    return 0;
}
