#include <stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int rows = matSize;
    int cols = matColSize[0];

    int steps = k % cols;
    if (steps == 0) return true;

    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            if (mat[row][(col + steps) % cols] != mat[row][col])
                return false;

    return true;
}