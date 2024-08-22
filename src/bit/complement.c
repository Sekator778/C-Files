#include <stdio.h>

int find_complement(int num) {
    // Find the bit length of the number
    unsigned int mask = ~0; // Start with all bits set to 1
    while (num & mask) {  // Create a mask that has the same bit length as num
        mask <<= 1;  // Shift left to increase the number of bits
    }
    
    // XOR the number with the mask to flip the bits
    return ~mask & ~num;
}

int main() {
    int num = 5;  // Example number
    int complement = find_complement(num);
    
    printf("The complement of %d is %d\n", num, complement);
    
    return 0;
}
