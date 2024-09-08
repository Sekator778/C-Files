#include <unistd.h>

extern int grid[4][4];

void ft_putnbr(int n) {
    char c = n + '0';
    write(1, &c, 1);
}

void print_grid() {
    int i = 0, j;

    while (i < 4) {
        j = 0;
        while (j < 4) {
            ft_putnbr(grid[i][j]);
            if (j < 3) {
                write(1, " ", 1);
            }
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}