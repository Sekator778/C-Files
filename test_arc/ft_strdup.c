#include <stdlib.h>
#include <stdio.h> // Додаємо для відладкового виводу

int length(char *src)
{
    int l = 0;
    while (src[l])
    {
        printf("Char: %c, ASCII: %d\n", src[l], src[l]); // Виводимо символ та його ASCII код
        l++;
    }
    return l;
}

char *ft_strdup(char *src)
{
    char *dup;
    int l = length(src); // Викликаємо length для підрахунку довжини рядка

    dup = (char *)malloc((l + 1) * sizeof(char)); // Виділяємо пам'ять для дубліката
    if (dup == NULL)
    {
        return NULL; // Перевіряємо, чи вдалося виділити пам'ять
    }

    int i = 0;
    while (src[i])
    {
        dup[i] = src[i]; // Копіюємо символи
        i++;
    }
    dup[i] = '\0'; // Додаємо null-термінатор в кінці
    return dup;
}

int main()
{
    char *test1 = "hello\nworld\t42";  // Рядок з новим рядком і табуляцією
    char test2[] = "hello\0world";     // Рядок з `\0` в середині
    
    char *dup1 = ft_strdup(test1);
    char *dup2 = ft_strdup(test2);

    if (dup1 && dup2)
    {
        printf("Test 1: %s\n", dup1);  // Очікується: "hello\nworld\t42"
        printf("Test 2: %s\n", dup2);  // Очікується: "hello" (до \0)
    }

    free(dup1);
    free(dup2);

    return 0;
}