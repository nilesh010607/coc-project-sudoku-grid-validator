#include <stdio.h>

int grid[9][9] = {
    // A correct, completed Sudoku for testing
    {5,3,4, 6,7,8, 9,1,2},
    {6,7,2, 1,9,5, 3,4,8},
    {1,9,8, 3,4,2, 5,6,7},

    {8,5,9, 7,6,1, 4,2,3},
    {4,2,6, 8,5,3, 7,9,1},
    {7,1,3, 9,2,4, 8,5,6},

    {9,6,1, 5,3,7, 2,8,4},
    {2,8,7, 4,1,9, 6,3,5},
    {3,4,5, 2,8,6, 1,7,9}
};

/*
 // If you want to read grid from stdin instead of hard-coding,
 // uncomment the read_grid() call in main() and this function.
void read_grid() {
    printf("Enter 81 numbers (row-wise), values must be 1..9:\n");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (scanf("%d", &grid[i][j]) != 1) {
                printf("Invalid input\n");
                return;
            }
        }
    }
}
*/

// check_rows: return 1 if every row contains 1..9 exactly once, else 0
int check_rows() {
    for (int r = 0; r < 9; ++r) {
        int seen[10] = {0}; // index 1..9
        for (int c = 0; c < 9; ++c) {
            int val = grid[r][c];
            if (val < 1 || val > 9) return 0;        // invalid number
            if (seen[val]) return 0;                // duplicate in row
            seen[val] = 1;
        }
        // (optional) could verify all seen[1..9] == 1, but loop ensures that
    }
    return 1;
}

// check_columns: return 1 if every column contains 1..9 exactly once, else 0
int check_columns() {
    for (int c = 0; c < 9; ++c) {
        int seen[10] = {0};
        for (int r = 0; r < 9; ++r) {
            int val = grid[r][c];
            if (val < 1 || val > 9) return 0;        // invalid number
            if (seen[val]) return 0;                // duplicate in column
            seen[val] = 1;
        }
    }
    return 1;
}

// check_subgrids: return 1 if every 3x3 sub-grid contains 1..9 exactly once, else 0
int check_subgrids() {
    // iterate over top-left corner of each 3x3 box
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            int seen[10] = {0};
            // iterate inside the 3x3 box
            for (int r = boxRow; r < boxRow + 3; ++r) {
                for (int c = boxCol; c < boxCol + 3; ++c) {
                    int val = grid[r][c];
                    if (val < 1 || val > 9) return 0;    // invalid number
                    if (seen[val]) return 0;            // duplicate in box
                    seen[val] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    // If you prefer interactive input, uncomment:
    // read_grid();

    int rows_ok = check_rows();
    int cols_ok = check_columns();
    int boxes_ok = check_subgrids();

    if (rows_ok && cols_ok && boxes_ok) {
        printf("Sudoku solution is VALID.\n");
    } else {
        printf("Sudoku solution is INVALID.\n");
    }

    return 0;
}