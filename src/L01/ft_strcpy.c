#include <stdio.h>

char *ft_strcpy(char *s1, char *s2) {
    char *dest = s1;  // Save the original pointer to s1

    while ((*s1++ = *s2++));  // Copy s2 to s1, including the null terminator

    return dest;  // Return the original pointer to s1
}
