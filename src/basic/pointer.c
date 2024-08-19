#include <stdio.h>

void printAge(int *age)
{
    printf("You are %d years old\n", *age);
}

int main()
{
    int age = 21;
    int *pAge = NULL;
    pAge = &age;
   

    printf("address of age: %16p\n", &age);
    printf("value of pAge: %16p\n", pAge);

    printf("size of age: %16d\n", sizeof(age));
    printf("size of pAge: %16d\n", sizeof(pAge));


    printf("value of age: %16d\n", age);
    printf("value at stored address: %16d\n", *pAge);

    printAge(pAge);


    return 0;
}