#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkerror(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		base_len;

	if (!checkerror(base))
		return;

	nb = nbr;
	base_len = ft_strlen(base);

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	ft_putchar(base[nb % base_len]);
}
//******************************************

void test_ft_putnbr_base() {
    // Тест 1: Десяткова система
    printf("Test 1 (Decimal):\nExpected: 42\nGot: ");
    ft_putnbr_base(42, "0123456789");
    printf("\n");

    // Тест 2: Двійкова система
    printf("Test 2 (Binary):\nExpected: 101010\nGot: ");
    ft_putnbr_base(42, "01");
    printf("\n");

    // Тест 3: Шістнадцяткова система
    printf("Test 3 (Hexadecimal):\nExpected: FF\nGot: ");
    ft_putnbr_base(255, "0123456789ABCDEF");
    printf("\n");

    // Тест 4: Вісімкова система (нестандартна)
    printf("Test 4 (Octal with custom symbols):\nExpected: veif\nGot: ");
    ft_putnbr_base(83, "ponveyif");
    printf("\n");

    // Тест 5: Негативне число (десяткова)
    printf("Test 5 (Negative Decimal):\nExpected: -42\nGot: ");
    ft_putnbr_base(-42, "0123456789");
    printf("\n");

    // Тест 6: Негативне число (двійкова)
    printf("Test 6 (Negative Binary):\nExpected: -101010\nGot: ");
    ft_putnbr_base(-42, "01");
    printf("\n");

    // Тест 7: Недійсна база (порожня)
    printf("Test 7 (Empty base):\nExpected: [nothing]\nGot: ");
    ft_putnbr_base(42, "");
    printf("\n");

    // Тест 8: Недійсна база (один символ)
    printf("Test 8 (One symbol base):\nExpected: [nothing]\nGot: ");
    ft_putnbr_base(42, "0");
    printf("\n");

    // Тест 9: Недійсна база (повторювані символи)
    printf("Test 9 (Duplicate characters):\nExpected: [nothing]\nGot: ");
    ft_putnbr_base(42, "01234abcdeabcd");
    printf("\n");

    // Тест 10: Недійсна база (заборонені символи + і -)
    printf("Test 10 (Invalid symbols):\nExpected: [nothing]\nGot: ");
    ft_putnbr_base(42, "01234+56789");
    printf("\n");
}
#include <stdio.h>
int main() {
    test_ft_putnbr_base();
	printf("Other tests *****************\n");
		ft_putnbr_base(894867, "0123456789");
	printf("\n");
	ft_putnbr_base(-12, "01");
	printf("\n");
	ft_putnbr_base(53, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(40, "poneyvif");
	printf("\n");
    return 0;
}
