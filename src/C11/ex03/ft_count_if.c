// int	ft_count_if(char **tab, int lenght, int (*f)(char*))
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (i < lenght)
// 		if (f(tab[i++]))
// 			count++;
// 	return (count);
// }
#include <stdio.h>

// Функція, яка перевіряє, чи містить рядок символ 'a'
int contains_a(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (1);  // Якщо містить 'a', повертаємо 1 (істина)
		i++;
	}
	return (0);  // Якщо немає 'a', повертаємо 0 (хибність)
}

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))  // Якщо функція повертає істину
			count++;    // Збільшуємо лічильник
		i++;
	}
	return (count);  // Повертаємо кількість елементів, що відповідають умові
}

int main()
{
	// Масив рядків
	char *array[] = {"hello", "world", "abc", "example", "banana"};

	// Рахуємо кількість рядків, які містять 'a'
	int result = ft_count_if(array, 5, contains_a);

	// Виводимо результат
	printf("Кількість рядків з літерою 'a': %d\n", result);

	return 0;
}
