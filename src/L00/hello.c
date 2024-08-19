#include <unistd.h>

void main(void) 
{
    write(1, "Hello world!\n", 13);
}