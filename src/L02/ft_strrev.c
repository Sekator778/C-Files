#include <stdio.h>
#include <stdlib.h>

int lenght(char *str)
{
    int l = 0;
    while (str[l])
    {
        l++;
    }
    return l;
}

char *ft_strrev(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    int l = lenght(str);
    char *reversedString = (char *)malloc((l + 1) * sizeof(char));
    if (reversedString == NULL)
    {
        fprintf(stderr, "Memory allocation failure");
        return NULL;
    }

    for (int i = 0; i < l; i++)
    {
        reversedString[i] = str[l - 1 - i];
    }
    reversedString[l] = '\0';

    return reversedString;
}

int main(void)
{
    char *s = "A$b  24b";

    char *reversed = ft_strrev(s);
    printf("%s\n", s);
    printf("%s\n", reversed);
    return 0;
}
