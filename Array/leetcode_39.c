/**
 * Problem: Combination Sum (LeetCode 39)
 * Time Complexity: O(2^N) - Backtracking
 * Memory Complexity: I really don't know - Sorry :(
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int* candidates, int candidatesSize, int target, int start, int* current_combination, int current_length, int*** result, int* returnSize, int** returnColumnSizes) {
    
    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(current_length * sizeof(int));
        for (int i = 0; i < current_length; i++)
            (*result)[*returnSize][i] = current_combination[i];

        (*returnColumnSizes)[*returnSize] = current_length;
        (*returnSize)++;

        return;
    }

    if (target < 0)
        return;

    for (int i = start; i < candidatesSize; i++) {
        current_combination[current_length] = candidates[i];

        backtrack(candidates, candidatesSize, target - candidates[i], i, current_combination, current_length + 1, result, returnSize, returnColumnSizes); 
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int max_combinations = 150;
    int** result = (int**)malloc(max_combinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_combinations * sizeof(int));
    *returnSize = 0;

    int* current_combination = (int*)malloc(30 * sizeof(int));

    backtrack(candidates, candidatesSize, target, 0, current_combination, 0, &result, returnSize, returnColumnSizes);

    free(current_combination);
    return result;
}