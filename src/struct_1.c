#include <stdio.h>
#include <string.h>

struct Player
{
    char name[12];
    int score;
};

int main()
{
    struct Player player1;
    strcpy(player1.name, "Alex");
    player1.score = 100;

    printf("name: %s\n", player1.name);
    printf("score: %d", player1.score);

    return 0;
}