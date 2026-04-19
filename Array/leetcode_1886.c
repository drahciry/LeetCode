/*
 * Problem: Determine Wheter Matrix Can Be Obtained By Rotation (LeetCode 1886)
 * Time Complexity: O(M x N) - M is the number of rows and N number of columns
 * Memory Complexity: O(1)
 */

#include <stdbool.h>

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    bool types_rotation[4] = {true, true, true, true};

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++) {
            if (mat[i][j] != target[i][j])
                types_rotation[0] = false;

            if (mat[matSize - 1 - j][i] != target[i][j])
                types_rotation[1] = false;

            if (mat[matSize - 1 - i][matSize - 1 - j] != target[i][j])
                types_rotation[2] = false;

            if (mat[j][matSize - 1 - i] != target[i][j])
                types_rotation[3] = false;
        }
    }

    return types_rotation[0] || types_rotation[1] || types_rotation[2] || types_rotation[3];
}