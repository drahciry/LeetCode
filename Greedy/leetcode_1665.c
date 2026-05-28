/**
 * Problem: Minimum Initial Energy to Finish Tasks (LeetCode 1665)
 * Time Complexity: O(N log N) - Because sorting is most dominant
 * Memory Complexity: O(log N) - Because stack of sorting
 */

#include <stdbool.h>

void swap(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int log2_int(unsigned int n) {
    int log = 0;
    if (n == 0) return -1;
    while (n >>= 1) log++;
    return log;
}

void median_of_three(int** arr, int left, int right) {
    if (right - left < 2) return;

    int mid = left + (right - left) / 2;

    if (arr[left][1] - arr[left][0] > arr[mid][1] - arr[mid][0])
        swap(&arr[left], &arr[mid]);
    if (arr[left][1] - arr[left][0] > arr[right][1] - arr[right][0])
        swap(&arr[left], &arr[right]);
    if (arr[mid][1] - arr[mid][0] > arr[right][1] - arr[right][0])
        swap(&arr[mid], &arr[right]);

    swap(&arr[left], &arr[mid]);
}

int partition(int** arr, int left, int right) {
    median_of_three(arr, left, right);

    int i = left - 1;
    int j = right + 1;

    int pivot = arr[left][1] - arr[left][0];

    while (true) {
        do {
            i++;
        } while (arr[i][1] - arr[i][0] > pivot);

        do {
            j--;
        } while (arr[j][1] - arr[j][0] < pivot);

        if (i >= j) return j;

        swap(&arr[i], &arr[j]);
    }
}

void _insertion_sort(int** arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int* key = arr[i];
        int j = i - 1;

        while (j >= left && (arr[j][1] - arr[j][0]) < (key[1] - key[0])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void heapify_arr(int** arr, int size, int idx) {
    int smallest;
    int left;
    int right;

    while (true) {
        smallest = idx;
        left = smallest * 2 + 1;
        right = smallest * 2 + 2;

        if (left < size && arr[left][1] - arr[left][0] < arr[smallest][1] - arr[smallest][0])
            smallest = left;
        if (right < size && arr[right][1] - arr[right][0] < arr[smallest][1] - arr[smallest][0])
            smallest = right;

        if (smallest == idx) break;

        swap(&arr[idx], &arr[smallest]);
        idx = smallest;
    }
}

void heap_sort_recursive(int** arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify_arr(arr, size, i);

    for (int i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify_arr(arr, i, 0);
    }
}

void _heap_sort(int** arr, int left, int right) {
    int partition_size = right - left + 1;
    heap_sort_recursive(arr + left, partition_size);
}

void _intro_sort(int** arr, int left, int right, int depth) {
    while (left < right) {
        if (right - left + 1 <= 10) {
            _insertion_sort(arr, left, right);
            return;
        }

        if (depth == 0) {
            _heap_sort(arr, left, right);
            return;
        }

        int split_index = partition(arr, left, right);
        int left_size = split_index - left;
        int right_size = right - split_index;

        if (left_size < right_size) {
            _intro_sort(arr, left, split_index, depth - 1);
            left = split_index + 1;
        } else {
            _intro_sort(arr, split_index + 1, right, depth - 1);
            right = split_index;
        }
    }
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    _intro_sort(tasks, 0, tasksSize - 1, log2_int((unsigned int)tasksSize));

    int current_energy = 0;
    int total_added = 0;

    for (int i = 0; i < tasksSize; i++) {
        int actual = tasks[i][0];
        int minimum = tasks[i][1];

        if (current_energy < minimum) {
            total_added += (minimum - current_energy);
            current_energy = minimum;
        }

        current_energy -= actual;
    }

    return total_added;
}