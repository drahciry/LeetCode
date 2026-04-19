/*
 * Problem: 3Sum (LeetCode 15)
 * Time Complexity: O(N³)
 * Memory Complexity: O(N) - Because of temporary array in Merge Sort
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

void insertion_sort(int* arr, int left, int right) {
    for (int i = left; i <= right; i++) {
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
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (k = left; k <= right; k++)
        arr[k] = temp[k];
}

void merge_sort_recursive(int* arr, int* temp, int left, int right) {
    if (left >= right) return;

    if (right - left + 1 <= 10) {
        insertion_sort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort_recursive(arr, temp, left, mid);
    merge_sort_recursive(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

void merge_sort(int* arr, int size) {
    if (size < 2) return;

    int* temp = (int*)malloc(size * sizeof(int));
    if (temp == NULL) return;

    merge_sort_recursive(arr, temp, 0, size - 1);

    free(temp);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 5000;
    int** solution = (int**)malloc(capacity * sizeof(int*));
    *returnSize = 0;

    if (numsSize < 3) return solution;

    merge_sort(nums, numsSize);

    for (int k = 0; k < numsSize - 2; k++) {
        if (nums[k] > 0) break;
        if (k != 0 && nums[k] == nums[k - 1]) continue;

        int target = -nums[k];
        int i = k + 1;
        int j = numsSize - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                if (*(returnSize) == capacity) {
                    capacity *= 2;
                    solution = (int**)realloc(solution, capacity * sizeof(int*));
                }
                
                solution[*returnSize] = (int*)malloc(3 * sizeof(int));
                solution[*returnSize][0] = nums[i];
                solution[*returnSize][1] = nums[j];
                solution[*returnSize][2] = nums[k];

                (*returnSize)++;

                i++;
                j--;
                while (i < j && nums[i] == nums[i - 1]) i++;
                while (i < j && nums[j] == nums[j + 1]) j--;
            }
        }
    }

    int* columnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < (*returnSize); i++) columnSizes[i] = 3;
    *returnColumnSizes = columnSizes;

    return solution;
}