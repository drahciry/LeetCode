/**
 * Problem: Check if Array is Good (LeetCode 2784)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <stdbool.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isGood(int* nums, int numsSize) {
    int i = 0;

    while (i < numsSize) {
        if (nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            swap(&nums[i], &nums[nums[i] - 1]);
        } else i++;
    }

    for (int i = 0; i < numsSize - 1; i++)
        if (nums[i] != (i + 1)) return false;

    return nums[numsSize - 1] == numsSize - 1;
}