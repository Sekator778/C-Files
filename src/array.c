#include <stdio.h>

int main() {
   double prices[] = {5.0, 10.0, 12.25, 23.5, 16.8};

   for (int i = 0; i < 5; i++)
   {
    printf("The %d price is %.2lf\n", i, prices[i]);
   }
   
    return 0;
}