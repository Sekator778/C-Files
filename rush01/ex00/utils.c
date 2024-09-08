#include <stdlib.h>

int *parse_input(char *str) {
    int *viewpoints = malloc(16 * sizeof(int));
    int i = 0;

    while (i < 16) {
        viewpoints[i] = str[i * 2] - '0';
        i++;
    }
    return viewpoints;
}

