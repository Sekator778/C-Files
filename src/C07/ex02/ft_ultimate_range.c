#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max){

    int length;
    int i;

    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    length = max - min;
    *range = malloc(length * sizeof(int));
    if (*range == NULL)
        return (-1);
    i = 0;
    while (i < length)
    {
        (*range)[i] = min;
        i++;
        min++;
    }
    return (length);
}

int main(void)
{
    int min = -3;
    int max = 5;
    int *range;
    int size;

    printf("Before min: %d\nand max: %d\n", min, max);

    size = ft_ultimate_range(&range, min, max);

    if (size == -1)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    else if (size == 0)
    {
        printf("Invalid range\n");
        return 0;
    }

    printf("Allocated range of size: %d\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(range);

    return 0;
}