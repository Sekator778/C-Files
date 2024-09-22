unsigned char reverse_bits(unsigned char octet)
{
    unsigned char reversed = 0;
    int i;

    for (i = 0; i < 8; i++)
    {
        // Shift the current reversed value to the left to make space
        reversed = (reversed << 1) | (octet & 1);  // Add the least significant bit of octet to reversed
        octet >>= 1;  // Shift octet to the right to process the next bit
    }

    return reversed;
}
