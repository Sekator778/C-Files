
int ft_atoi(const char *str)
{
    int result = 0;  // Initialize result to 0
    int sign = 1;    // Initialize sign to 1 (positive)

    // Skip whitespace characters
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
    {
        str++;
    }

    // Check for sign indicator ('-' or '+')
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;  // If negative sign, change sign to -1
        str++;
    }

    // Convert characters to integer
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    // Apply sign
    return (result * sign);
}
