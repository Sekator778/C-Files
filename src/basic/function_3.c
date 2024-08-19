#include <stdio.h>

// void birthday(char name[], int age); // function prototype
int main() {
    char name[] = "Alex";
    int age = 46;

    birthday(name);

    return 0;
}


void birthday(char name[], int age)
{
    printf("\nHappy day dear %s!", name);
    printf("\nYou are %d years old!", age);

}