#include <unistd.h>

void ft_putnbr(int n)
{
    if (n == -2147483648) // Handle the minimum int value case
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
        ft_putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    // Skip leading whitespace
    while (*str == ' ' || *str == '\t' || *str == '\n' ||
           *str == '\v' || *str == '\f' || *str == '\r')
    {
        str++;
    }

    // Handle sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        int digit = *str - '0';
        result = result * 10 + digit;
        str++;
    }
    return sign * result;
}

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int num = ft_atoi(argv[1]);
        if (num < 2)
        {
            write(1, "0\n", 2);
            return 0;
        }

        int sum = 0;
        for (int i = 2; i <= num; i++)
        {
            if (is_prime(i))
            {
                sum += i;
            }
        }
        ft_putnbr(sum);
    }
    else
    {
        write(1, "0", 1);
    }
    write(1, "\n", 1);
    return 0;
}