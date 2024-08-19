#include <stdio.h>

void sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int prices[] = {5, 10, 12, 23, 16};
    int size = sizeof(prices) / sizeof(prices[0]);

    for (int i = 0; i < size - 1; i++)
    {
        printf("%d\t", prices[i]);
    }
    return 0;
}