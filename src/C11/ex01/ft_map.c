#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ret;
	int	i;

	i = 0;
	ret = (int *)malloc(sizeof(int) * (length));
	if (!ret) // Перевірка чи успішно виділено пам'ять
		return (NULL);
	while (i < length)
		ret[i] = (*f)(tab[i++]);
	return (ret);
}

// Функція, яка підносить число до квадрата
int	square(int n)
{
	return (n * n);
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int length = sizeof(array) / sizeof(array[0]);
	int *result;
	int i;

	// Викликаємо ft_map і передаємо функцію square
	result = ft_map(array, length, square);

	// Виводимо результати
	if (result)
	{
		for (i = 0; i < length; i++)
			printf("%d ", result[i]);
		printf("\n");

		// Не забуваємо звільнити пам'ять, виділену функцією ft_map
		free(result);
	}

	return 0;
}
