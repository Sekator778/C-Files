#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc > 1) // Check if there is at least one argument
    {
        while (*argv[1]) // Loop through the first argument
        {
            write(1, argv[1]++, 1); // Write each character
        }
    }
    write(1, "\n", 1); // Always write a newline at the end
    return 0; // Return 0 to indicate successful execution
}
