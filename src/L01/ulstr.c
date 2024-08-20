#include <unistd.h>

// Function to change the case of a character in place
void changeCase(char *ch)
{
    if (*ch >= 'a' && *ch <= 'z') // If it's a lowercase letter
    {
        *ch = *ch - 32; // Convert to uppercase
    }
    else if (*ch >= 'A' && *ch <= 'Z') // If it's an uppercase letter
    {
        *ch = *ch + 32; // Convert to lowercase
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i])
        {
            changeCase(&argv[1][i]); // Pass a pointer to the character
            i++;
        }
        write(1, argv[1], i); // Write the entire modified string
        write(1, "\n", 1);
    }
    return 0;
}
