/*
 * Problem: Find First and Last Position of Element in Sorted Array (LeetCode 34)
 * Time Complexity: O(log N)
 * Memory Complexity: O(1)
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>

int find_bound(int* nums, int numsSize, int target, bool find_first) {
    int left = 0;
    int right = numsSize - 1;
    int bound = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            bound = mid;

            if (find_first)
                right = mid - 1;
            else
                left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return bound;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* solution = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    solution[0] = find_bound(nums, numsSize, target, true);
    solution[1] = find_bound(nums, numsSize, target, false);
    
    return solution;
}