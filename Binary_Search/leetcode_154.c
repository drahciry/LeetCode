/**
 * Problem: Find Minimum in Rotated Sorted Array II (LeetCode 154)
 * Time Complexity: Best Case (unique elements) - O(log N) | Worst Case (non-unique elements) - O(N)
 * Memory Complexity: O(1)
 */

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    if (nums[left] < nums[(left + 1) % numsSize])
        return nums[left];

    int min_num = 5001;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] < min_num)
            min_num = nums[i];

    return min_num;
}