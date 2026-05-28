/**
 * Problem: Rotating the Box (LeetCode 1861)
 * Time Complexity: O(M x N) - M is the width of box and N is the length of box
 * Memory Complexity: O(1)
 */

#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {
    int rows = boxGridSize;
    int cols = boxGridColSize[0];

    *returnSize = cols;
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    char** rotateBox = (char**)malloc(cols * sizeof(char*));
    for (int row = 0; row < cols; row++) {
        rotateBox[row] = (char*)malloc(rows * sizeof(char));
        (*returnColumnSizes)[row] = rows;
    }

    for (int row = 0; row < rows; row++) {
        int emptySpot = cols - 1;
        for (int col = cols - 1; col >= 0; col--){
            int rotRow = col;
            int rotCol = rows - row - 1;

            if (boxGrid[row][col] == '*') {
                rotateBox[rotRow][rotCol] = '*';
                emptySpot = col - 1;
            } else if (boxGrid[row][col] == '#') {
                rotateBox[rotRow][rotCol] = '.';
                rotateBox[emptySpot][rotCol] = '#';
                emptySpot--;
            } else rotateBox[rotRow][rotCol] = '.';
        }
    }

    return rotateBox;
}