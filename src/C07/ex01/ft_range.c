#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int length;
    int *range;
    int i;

    if (min >= max)
        return (NULL);
    length = max - min;
    range = malloc(length * sizeof(int));
    if (range == NULL)
        return (NULL);
    i = 0;
    while (i < length)
    {
        range[i] = min;
        i++;
        min++;
    }
    return (range);
}

int main(void)
{
    int min = -3;
    int max = -5;

    printf("Before min: %d\nand max: %d\n", min, max);

    int *range = ft_range(min, max);

    for (int i = 0; i < max - min; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(range);

    return 0;
}