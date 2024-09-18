int	ft_is_sort(int *tab, int lenght, int (*f)(int, int))
{
	int	i;
	int	k;

	i = 0;
	while (i < lenght - 1)
	{
		k = i + 1;
		if (f(tab[i], tab[k]) < 0)
			return (-1);
		else if (f(tab[i], tab[k]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int compare_ascending(int a, int b)
{
    return a - b;
}

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));
int compare_ascending(int a, int b);

int main()
{
    int array_sorted[] = {5, 4, 3, 2, 1};  // Спадний порядок
    int array_unsorted[] = {1, 2, 3, 4, 5};  // Зростаючий порядок
    int array_random[] = {3, 1, 4, 2, 5};  // Невпорядкований

    // Перевіряємо масиви
    int result_sorted = ft_is_sort(array_sorted, sizeof(array_sorted) / sizeof(array_sorted[0]), compare_ascending);
    printf("Array sorted: %s\n", result_sorted == 1 ? "Yes" : "No");

    int result_unsorted = ft_is_sort(array_unsorted, sizeof(array_unsorted) / sizeof(array_unsorted[0]), compare_ascending);
    printf("Array unsorted: %s\n", result_unsorted == 1 ? "Yes" : "No");

    int result_random = ft_is_sort(array_random, sizeof(array_random) / sizeof(array_random[0]), compare_ascending);
    printf("Array random: %s\n", result_random == 1 ? "Yes" : "No");

    return 0;
}
