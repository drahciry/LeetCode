/**
 * Problem: Minimum Element After Replacement With Digit Sum (LeetCode 3300)
 * Time Complexity: O(N x log a) - N is the nums size and a is the biggest value in array
 * Memory Complexity: O(1)
 */

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int minElement(int* nums, int numsSize) {
    int minSum = 10000;

    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        int num = nums[i];

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        minSum = min(minSum, sum);
    }

    return minSum;
}