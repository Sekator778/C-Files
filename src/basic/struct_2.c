#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[12];
    int score;
} Player;

int main()
{
    Player player1 = {
        "Alex",
        100};

    printf("name: %s\n", player1.name);
    printf("score: %d", player1.score);

    return 0;
}