#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *src)
{
    int l = 0;
    while (src[l])
    {
        l++;
    }
    return (l);
}

char *ft_strdup(char *src)
{
    char *dest;
    int i;
    int length;

    if (src == NULL)
        return (NULL);

    i = 0;
    length = ft_strlen(src) + 1;
    dest = malloc(sizeof(char) * length);
    if (dest == NULL)
        return (dest);

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    // Вивід для перевірки
    printf("Source: '%s'\n", src);
    printf("Destination: '%s'\n", dest);

    return (dest);
}

int main()
{
    char *result;

    // Тест 1: Звичайний рядок
    result = ft_strdup("hello");
    printf("Test 1 Result: '%s'\n", result);
    free(result);

    // Тест 2: Рядок із символом нового рядка
    result = ft_strdup("bienvenue\n");
    printf("Test 2 Result: '%s'\n", result);
    free(result);

    // Тест 3: Порожній рядок
    result = ft_strdup("");
    printf("Test 3 Result: '%s'\n", result);
    free(result);

    // Тест 4: Рядок із кількома пробілами
    result = ft_strdup("  42  ");
    printf("Test 4 Result: '%s'\n", result);
    free(result);

    // Тест 5: Рядок з лише символом нового рядка
    result = ft_strdup("\n");
    printf("Test 5 Result: '%s'\n", result);
    free(result);

    return 0;
}
