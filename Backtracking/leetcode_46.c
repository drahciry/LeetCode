/**
 * Problem: Permutation (LeetCode 46)
 * Time Complexity: O(N x N!)
 * Memory Complexity: O(N)
 */

#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int fatorial(int num) {
    int result = 1;

    while (num > 1) {
        result *= num;
        num--;
    }

    return result;
}

void backtrack(int* nums, int numsSize, int** solution, int* path, bool* used, int depth, int* n) {
    if (depth == numsSize) {
        for (int i = 0; i < numsSize; i++)
            solution[*n][i] = path[i];
        (*n)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            path[depth] = nums[i];
            used[i] = true;

            backtrack(nums, numsSize, solution, path, used, depth + 1, n);

            used[i] = false;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = fatorial(numsSize);
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    int** solution = (int**)malloc((*returnSize) * sizeof(int*));

    for (int i = 0; i < (*returnSize); i++) {
        solution[i] = (int*)malloc(numsSize * sizeof(int));
        (*returnColumnSizes)[i] = numsSize;
    }

    int* path = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(int));

    int n = 0;
    backtrack(nums, numsSize, solution, path, used, 0, &n);

    free(path);
    free(used);

    return solution;
}