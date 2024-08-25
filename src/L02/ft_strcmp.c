#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] == s2[i])
        {
            i++;
            continue;
        }
        else
        {
            return 0;
        }
    }
    if (s1[i] != '\0' || s2[i] != '\0')
    {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    char *s1 = "hello";
    char *s2 = "hello world";
    int result = ft_strcmp(s1, s2);

    if (result == 1)
        write(1, "1\n", 2); // Print 1 if strings are identical
    else
        write(1, "0\n", 2); // Print 0 if strings are different

    return 0;
}