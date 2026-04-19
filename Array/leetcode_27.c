/*
 * Problem: Remove Duplicates from Sorted Array (LeetCode 27)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) return 0;

    int j = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] != val)
            nums[j++] = nums[i];

    return j;
}