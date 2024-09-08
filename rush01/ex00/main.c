#include <stdlib.h>
#include <unistd.h>

int can_place_number(int row, int col, int num);
int solve(int *viewpoints, int row, int col);
int count_visible_boxes(int *arr);
int check_row_visibility(int *viewpoints, int row);
int check_col_visibility(int *viewpoints, int col);

void ft_putnbr(int n);
void print_grid();
int *parse_input(char *str);

int grid[4][4];

int main(int argc, char **argv) {
    if (argc != 2 || argv[1][31] != '\0') {
        write(1, "Invalid input\n", 14);
        return 1;
    }

    int *viewpoints = parse_input(argv[1]);

    if (solve(viewpoints, 0, 0)) {
        print_grid();
    } else {
        write(1, "The puzzle cannot be solved\n", 29);
    }
    free(viewpoints);
    return 0;
}
