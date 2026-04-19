/*
 * Problem: Maximum Subarray (LeetCode 53)
 * Time Complexity: O(N)
 * Memory Complexyt: O(1)
 */

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        currentSum = MAX(nums[i], currentSum + nums[i]);
        maxSum = MAX(maxSum, currentSum);
    }

    return maxSum;
}