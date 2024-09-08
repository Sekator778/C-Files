#include <stdlib.h>

int *parse_input(char *str) {
    int *viewpoints = malloc(16 * sizeof(int));
    for (int i = 0; i < 16; i++) {
        viewpoints[i] = str[i * 2] - '0';
    }
    return viewpoints;
}
