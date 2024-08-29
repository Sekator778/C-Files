#include <stdio.h>

void print_bits(unsigned int num)
{
    int bits = sizeof(num) * 8; // Визначаємо кількість бітів в числі (32 біти для int)
    unsigned int mask = 1 << (bits - 1); // Створюємо маску для найстаршого біта
    
    for (int i = 0; i < bits; i++)
    {
        if (num & mask)  // Побітове І з маскою для перевірки поточного біта
            printf("1");
        else
            printf("0");

        mask >>= 1; // Зсуваємо маску вправо для наступного біта
    }
    printf("\n");
}

int main()
{
    int num = 5;  // Наприклад, число 5
    print_bits(num);
    return 0;
}
