/**
 * Problem: Check if Array Is Sorted and Rotated (LeetCode 1752)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <stdbool.h>

bool check(int* nums, int numsSize) {
    int drops = 0;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] > nums[(i + 1) % numsSize])
            drops++;

    return (drops <= 1);
}