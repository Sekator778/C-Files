#include <stdio.h>

int main() {
   double prices[] = {5.0, 10.0, 12.25, 23.5, 16.8};
   int size1 = sizeof(prices);
   printf("first size: %d\n", size1);

    int size2 = sizeof(prices[0]);
   printf("second size: %d\n", size2);


   size_t array_size = sizeof(prices) / sizeof(prices[0]);

   for (size_t i = 0; i < array_size; i++) {
       printf("The %zu price is %.2lf\n", i + 1, prices[i]);
   }
   
   return 0;
}
