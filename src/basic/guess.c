#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MIN = 1;
    const int MAX = 100;

    srand(time(0));

    int answer = (rand() % MAX) + MIN;
    int guesses = 0;
    int guess;

    do
    {
        printf("Input your number for the game (between 1 and 100): ");
        scanf("%d", &guess);

        // Use the ternary operator to check if the input is out of range
        (guess < MIN || guess > MAX) 
            ? printf("Invalid input. Please enter a number between %d and %d.\n", MIN, MAX) 
            : (
                guesses++, 
                guess < answer 
                    ? printf("The answer is higher.\n") 
                    : (guess > answer ? printf("The answer is lower.\n") : 0)
              );

    } while (guess != answer);

    printf("Congratulations! You guessed the correct answer %d in %d attempts.\n", answer, guesses);

    return 0;
}
