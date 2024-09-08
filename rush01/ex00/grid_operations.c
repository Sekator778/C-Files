#include <stdlib.h>

int check_row_visibility(int *viewpoints, int row);
int check_col_visibility(int *viewpoints, int col);
void get_next_position(int row, int col, int *next_row, int *next_col);
int is_valid_placement(int *viewpoints, int row, int col);

extern int grid[4][4];
// Function checks if a number can be placed in the cell without duplication in the row or column
// Parameters:
// - row: index of the row
// - col: index of the column
// - num: the number to be placed
// Returns:
// - 1 if the number can be placed
// - 0 if the number already exists in the row or column
int can_place_number(int row, int col, int num) {
    int i = 0;

    while (i < 4) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return (0);
        }
        i++;
    }
    return 1;
}

// Function solves the puzzle by placing numbers in the grid using recursion (backtracking)
// Parameters:
// - viewpoints: array of visibility values (views from top, bottom, left, right)
// - row: index of the current row
// - col: index of the current column
// Returns:
// - 1 if the puzzle is solved successfully
// - 0 if placement is unsuccessful
int solve(int *viewpoints, int row, int col) {
    if (row == 4) {
        return 1;
    }
    int next_row, next_col;
    get_next_position(row, col, &next_row, &next_col);

    int num = 1;
    while (num <= 4) {
        if (can_place_number(row, col, num)) {
            grid[row][col] = num;
            if (!is_valid_placement(viewpoints, row, col)) {
                grid[row][col] = 0;
                num++;
                continue;
            }
            if (solve(viewpoints, next_row, next_col)) {
                return 1;
            }
        }
        num++;
    }

    grid[row][col] = 0;
    return 0;
}
// Function calculates the next position in the grid
// Parameters:
// - row: current row index
// - col: current column index
// - next_row: pointer to the variable to store the next row
// - next_col: pointer to the variable to store the next column
void get_next_position(int row, int col, int *next_row, int *next_col) {
    if (col == 3) {
        *next_row = row + 1;
        *next_col = 0;
    } else {
        *next_row = row;
        *next_col = col + 1;
    }
}
// Function checks if the number placement is valid with respect to visibility rules
// Parameters:
// - viewpoints: array of visibility values (views from top, bottom, left, right)
// - row: index of the current row
// - col: index of the current column
// Returns:
// - 1 if the placement satisfies the visibility rules
// - 0 if the visibility rules are violated
int is_valid_placement(int *viewpoints, int row, int col) {
    if (col == 3) {
        if (!check_row_visibility(viewpoints, row)) {
            return 0;
        }
    }
    if (row == 3) {
        if (!check_col_visibility(viewpoints, col)) {
            return 0;
        }
    }
    return (1);
}