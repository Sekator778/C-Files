#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i = 0;
        int word_started = 0;

        // Skip leading spaces and tabs
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;

        // Process the string
        while (argv[1][i])
        {
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                if (word_started)
                    write(1, " ", 1); // Add a space before the next word if needed
                while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
                {
                    write(1, &argv[1][i], 1);
                    i++;
                }
                word_started = 1; // Mark that a word has started
            }
            else
            {
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}
