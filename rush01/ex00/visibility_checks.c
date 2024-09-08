#include <stdlib.h>

extern int grid[4][4];
// Function counts the number of visible boxes from a given direction
// Parameters:
// - arr: array of box heights in the current row or column
// Returns:
// - The number of visible boxes based on height visibility rules
int count_visible_boxes(int *arr) {
    int max_height = 0;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i] > max_height) {
            max_height = arr[i];
            count++;
        }
    }
    return count;
}
// Function checks the row visibility from left to right and right to left
// Parameters:
// - viewpoints: array of visibility values for rows and columns
// - row: index of the current row
// Returns:
// - 1 if the visibility for the row is correct
// - 0 if the visibility for the row is incorrect
int check_row_visibility(int *viewpoints, int row) {
    int row_left[4], row_right[4];
    for (int i = 0; i < 4; i++) {
        row_left[i] = grid[row][i];
        row_right[i] = grid[row][4 - i - 1];
    }

    if (viewpoints[8 + row] != count_visible_boxes(row_left) ||
        viewpoints[12 + row] != count_visible_boxes(row_right)) {
        return 0;
    }
    return 1;
}
// Function checks the column visibility from top to bottom and bottom to top
// Parameters:
// - viewpoints: array of visibility values for rows and columns
// - col: index of the current column
// Returns:
// - 1 if the visibility for the column is correct
// - 0 if the visibility for the column is incorrec
int check_col_visibility(int *viewpoints, int col) {
    int col_up[4], col_down[4];
    for (int i = 0; i < 4; i++) {
        col_up[i] = grid[i][col];
        col_down[i] = grid[4 - i - 1][col];
    }

    if (viewpoints[col] != count_visible_boxes(col_up) ||
        viewpoints[4 + col] != count_visible_boxes(col_down)) {
        return 0;
    }
    return 1;
}
