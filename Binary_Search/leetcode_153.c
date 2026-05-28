/**
 * Problem: Find Minimum in Rotated Sorted Array
 * Time Complexity: O(log n) - Binary Search
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

    return nums[left];
}