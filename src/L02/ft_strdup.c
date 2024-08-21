#include <stdio.h>
#include <stdlib.h> // Needed for malloc

int length(char *src)
{
    int l = 0;
    while (src[l])
    {
        l++;
    }
    return l;
}
char *ft_strdup(char *src)
{
    char *dup;
    int l = length(src);

    dup = (char *)malloc((l + 1) * sizeof(char));
    if (dup == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0'; // Null-terminate the duplicated string
    return dup;
}

int main(void)
{
    char s[] = "Abc";
    char *result = ft_strdup(s);
    printf("%s\n", result);

    return 0;
}