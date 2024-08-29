#include <stdio.h>

// Function to print the bit representation of an integer
void print_bits(unsigned int num)
{
    int bits = sizeof(num) * 8; // Determine the number of bits in the integer (32 bits for int)
    unsigned int mask = 1 << (bits - 1); // Create a mask for the most significant bit (leftmost bit)
    
    for (int i = 0; i < bits; i++)
    {
        if (num & mask)  // Bitwise AND with the mask to check the current bit
            printf("1");
        else
            printf("0");

        mask >>= 1; // Shift the mask to the right for the next bit
    }
    printf("\n");
}

int main()
{
    int num;

    // Prompt the user to enter an integer
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Print the bit representation of the entered number
    printf("Original bit representation: ");
    print_bits(num);

    // Perform bitwise inversion
    int inverted_num = ~num;

    // Print the bit representation of the inverted number
    printf("Inverted bit representation: ");
    print_bits(inverted_num);

    // Print the result of the inversion
    printf("Result after inversion: %d\n", inverted_num);

    return 0;
}
