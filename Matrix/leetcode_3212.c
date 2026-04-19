#include <string.h>
#include <stdbool.h>

#define MAX_COLS 1000

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int output = 0;
    int rows = gridSize;
    int cols = gridColSize[0];

    int current_balances[MAX_COLS];
    bool has_x_in_col[MAX_COLS];

    memset(current_balances, 0, cols * sizeof(int));
    memset(has_x_in_col, false, cols * sizeof(bool));

    for (int i = 0; i < rows; i++) {
        int row_balance = 0;
        bool row_has_x = false;

        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'X') {
                row_balance++;
                row_has_x = true;
            } else if (grid[i][j] == 'Y') {
                row_balance--;
            }

            current_balances[j] += row_balance;

            if (row_has_x) {
                has_x_in_col[j] = true;
            }

            if (current_balances[j] == 0 && has_x_in_col[j])
                output++;
        }
    }

    return output;
}