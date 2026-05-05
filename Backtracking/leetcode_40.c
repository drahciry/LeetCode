/**
 * Problem: Combination Sum II (LeetCode 40)
 * Time Complexity: O(2^N) - Backtracking
 * Memory Complexity: I really don't know - Sorry :(
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

void insertion_sort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int* arr, int* temp, int left, int mid, int right) {
    int i = left;
    int k = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (k = left; k <= right; k++)
        arr[k] = temp[k];
}

void merge_recursive(int* arr, int* temp, int left, int right) {
    if (left >= right) return;

    if (left + (right - left) / 2) {
        insertion_sort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    merge_recursive(arr, temp, left, mid);
    merge_recursive(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

void merge_sort(int* arr, int size) {
    if (size <= 1) return;

    int* temp = (int*)malloc(size * sizeof(int));
    if (temp == NULL) return;

    merge_recursive(arr, temp, 0, size - 1);

    free(temp);
}

void backtrack(int* candidates, int candidatesSize, int target, int start, int* current_combination, int current_length, int*** result, int* returnSize, int** returnColumnSizes) {

    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(current_length * sizeof(int));
        for (int i = 0; i < current_length; i++)
            (*result)[*returnSize][i] = current_combination[i];

        (*returnColumnSizes)[*returnSize] = current_length;
        (*returnSize)++;

        return;
    }

    if (target < 0) return;

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) break;

        if (i > start && candidates[i] == candidates[i - 1]) continue;

        current_combination[current_length] = candidates[i];

        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, current_combination, current_length + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int max_combination = 150;
    int** result = (int**)malloc(max_combination * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_combination * sizeof(int));
    *returnSize = 0;

    int* current_combination = (int*)malloc(35 * sizeof(int));
    merge_sort(candidates, candidatesSize);

    backtrack(candidates, candidatesSize, target, 0, current_combination, 0, &result, returnSize, returnColumnSizes);

    free(current_combination);
    return result;
}