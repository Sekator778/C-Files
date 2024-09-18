// int	ft_any(char **tab, int (*f)(char*))
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		if (f(tab[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

#include <stdio.h>

// Приклад функції, яка перевіряє, чи містить рядок символ 'a'
int contains_a(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (1);  // Якщо рядок містить 'a', повертаємо 1
		i++;
	}
	return (0);  // Інакше повертаємо 0
}

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))  // Викликаємо функцію для кожного рядка
			return (1);  // Якщо хоч один елемент відповідає умові, повертаємо 1
		i++;
	}
	return (0);  // Якщо жоден елемент не відповідає умові, повертаємо 0
}

int main()
{
	// Масив рядків
	char *array[] = {"hello", "world", "abc", NULL};

	// Викликаємо ft_any і передаємо функцію contains_a
	int result = ft_any(array, contains_a);

	// Виводимо результат
	if (result)
		printf("Масив містить хоча б один рядок з літерою 'a'.\n");
	else
		printf("Жоден рядок не містить літери 'a'.\n");

	return 0;
}
