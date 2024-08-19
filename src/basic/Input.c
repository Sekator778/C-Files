#include <stdio.h>
#include <string.h>

int main() {
    char name[32]; 
    int age;

    printf("What's your name?\n");
    fgets(name, 32, stdin);
    name[strlen(name)-1] = '\0';
    printf("How old are you?\n");
    scanf("%d", &age);

    printf("Hello %s, how are you?\n", name);
    printf("You are %d years old.\n", age);
    return 0;
}