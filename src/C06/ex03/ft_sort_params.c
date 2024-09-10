#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void sort_arguments(char *args[], int size)
{
    int i;
    int j;
    char *temp;

    i = 1;
    while (i < size - 1)
    {
        j = 1;
        while (j < size - i)
        {
            if (ft_strcmp(args[j], args[j + 1]) > 0)
            {
                temp = args[j];
                args[j] = args[j + 1];
                args[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc > 1)
    {
        sort_arguments(argv, argc);
        i = 1;
        while (i < argc)
        {
            ft_putstr(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}