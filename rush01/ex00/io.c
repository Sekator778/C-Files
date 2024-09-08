#include <unistd.h>

extern int grid[4][4];

void ft_putnbr(int n) {
    char c = n + '0';
    write(1, &c, 1);
}

void print_grid() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ft_putnbr(grid[i][j]);
            if (j < 3) {
                write(1, " ", 1);
            }
        }
        write(1, "\n", 1);
    }
}
