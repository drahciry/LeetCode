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
            arr[j + 1] = arr[j]; j--;
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

void merge_sort(int* arr, int arrSize) {
    if (arrSize < 2) return;

    int* temp = (int*)malloc(arrSize * sizeof(int));
    if (temp == NULL) return;

    merge_sort_recursive(arr, temp, 0, arrSize - 1);

    free(temp);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) return NULL;

    int cap = 32;
    int** solution = (int**)malloc(cap * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cap * sizeof(int));

    merge_sort(nums, numsSize);

    for (int i = 0; i < numsSize - 3; i++) {
        if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        
        long sub_target = (long) target - nums[i];
        for (int j = i + 1; j < numsSize - 2; j++) {
            if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;

            sub_target = (long) target - nums[i] - nums[j];
            int k = j + 1;
            int p = numsSize - 1;

            while (k < p) {
                long sum = (long) nums[k] + nums[p];
                if (sum > sub_target) {
                    p--;
                } else if (sum < sub_target) {
                    k++;
                } else {
                    if (*returnSize == cap) {
                        cap *= 2;
                        solution = (int**)realloc(solution, cap * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, cap * sizeof(int));
                    }

                    solution[*returnSize] = (int*)malloc(4 * sizeof(int));
                    solution[*returnSize][0] = nums[i];
                    solution[*returnSize][1] = nums[j];
                    solution[*returnSize][2] = nums[k];
                    solution[*returnSize][3] = nums[p];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    k++; p--;
                    while (k < p && nums[k] == nums[k - 1]) k++;
                    while (k < p && nums[p] == nums[p + 1]) p--;
                }
            }
        }
        printf("\n");
    }

    return solution;
}