#include <unistd.h>

void main(void)
{
    int num1;
    int num2;
    char output[7];

    for (num1 = 0; num1 <= 98; num1++)
    {
        for (num2 = num1 + 1; num2 <= 99; num2++)
        {
            output[0] = '0' + num1 / 10;
            output[1] = '0' + num1 % 10;
            output[2] = ' ';
            output[3] = '0' + num2 / 10;
            output[4] = '0' + num2 % 10;
            if (num1 != 98 || num2 != 99)
            {
                output[5] = ',';
                output[6] = ' ';
                write(1, output, 7);
            }
            else
            {
                write(1, output, 5);
            }
        }
    }
}
