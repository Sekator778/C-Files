#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int size = (start <= end) ? (end - start + 1) : (start - end + 1);
    int *arr = (int *)malloc(size * sizeof(int));

    if (!arr)
        return NULL;

    int j = 0;
    if (start <= end)
    {
        for (int i = end; i >= start; i--)
        {
            arr[j++] = i;
        }
    }
    else
    {
        for (int i = end; i <= start; i++)
        {
            arr[j++] = i;
        }
    }
    return arr;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <start> <end>\n", argv[0]);
        return 1;
    }

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);

    printf("Start: %d, End: %d\n", start, end);

    int *arr = ft_rrange(start, end);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    int size = (start <= end) ? (end - start + 1) : (start - end + 1);

    // Using a pointer to iterate through the array
    int *ptr = arr;
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", *ptr);
        ptr++; // Move the pointer to the next element in the array
    }

    free(arr); // Free the allocated memory

    return 0;
}