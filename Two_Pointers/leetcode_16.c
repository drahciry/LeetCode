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

void merge_sort(int* arr, int size) {
    if (size < 2) return;

    int* temp = (int*)malloc(size * sizeof(int));
    if (temp == NULL) return;

    merge_sort_recursive(arr, temp, 0, size - 1);

    free(temp);
}

int abs(int number) {
    return (number > 0) ? number : -number;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    merge_sort(nums, numsSize);
    int close = nums[0] + nums[1] + nums[2];

    for (int k = 0; k < numsSize - 2; k++) {
        if (k != 0 && nums[k] == nums[k - 1]) continue;

        int i = k + 1;
        int j = numsSize - 1;

        int sum = nums[k] + nums[k + 1] + nums[k + 2];
        if ((sum > target) && abs(target - sum) > abs(target - close)) break;

        while (i < j) {
            sum = nums[i] + nums[j] + nums[k];

            if (sum == target) return sum;
            
            close = (abs(target - sum) < abs(target - close)) ? sum : close;
            if (sum < target) {
                i++;
                while (i < j && nums[i] == nums[i - 1]) i++;
            } else {
                j--;
                while (i < j && nums[j] == nums[j + 1]) j--;
            }
        }
    }

    return close;
}