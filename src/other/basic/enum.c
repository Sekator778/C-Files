#include <stdio.h>
#include <string.h>

enum Day
{
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 7
};

int main()
{
    enum Day today = SUNDAY;

    printf("today is: %d\n", today);

    if (today == SUNDAY || today == SATURDAY)
    {
        printf("Today time for a party");
    } else
    {
        printf("I have work today");
    }
    

    return 0;
}