#include <stdio.h>

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < lenght)
		f(tab[i++]);
}

void print(int n)
{
	printf("%i\n", n);
}

int main()
{
	int array[] = {1, 3, 4, 2, 8};
	int lenght = sizeof(array) / sizeof(int);

	ft_foreach(array, lenght, print);
}