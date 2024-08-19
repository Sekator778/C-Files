#include <stdio.h>

int main()
{
    int a = 'X';
    float b = 'Y';
    double c = 'Z';

    char arr[3];

    printf("a= %d\n", a);
    printf("b= %d\n", b);
    printf("c= %d\n", c);

    printf("arr= %d\n", arr);


    printf("%d bytes\n", sizeof(a));
    printf("%d bytes\n", sizeof(b));
    printf("%d bytes\n", sizeof(c));

    printf("%d bytes\n", sizeof(arr));


    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);

    printf("%p\n", &arr);



    return 0;
}