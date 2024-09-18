void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		len;
	int		i;
	char	*str;
	int		k;

	len = 0;
	i = 0;
	while (tab[len])
		len++;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if ((cmp)(tab[i], tab[k]) > 0)
			{
				str = tab[i];
				tab[i] = tab[k];
				tab[k] = str;
			}
			k++;
		}
		i++;
	}
	tab[i] = 0;
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char *str[4] = {"ciao","ciao2","ciao1"};
	ft_advanced_sort_string_tab(str, strcmp);

	int i = 0;
	while(str[i])
		printf("%s\n", str[i++]);

}*/
