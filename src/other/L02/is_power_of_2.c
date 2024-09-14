:wchar_t#include <stdio.h>
#include <unistd.h>

int is_power_of_2(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }

    if ((n % 2) == 0)
    {
        return 1;
    }
   // return (n & (n - 1) == 0);
    return 0;
}

void print_bits(unsigned int n)
{
    int numBits = sizeof(n) * 8;

    for (int i = numBits; i >= 0 ; i--)
    {
        unsigned int bit = (n >> i) & 1;
        char c = bit + '0';
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}

int main(void)
{
    unsigned int num = 64;
    
    printf("3: %d\n", is_power_of_2(3));
    printf("64: %d\n", is_power_of_2(64));
    
    printf("Binary representation of %u: ", num);
    print_bits(num);

    return 0;
}