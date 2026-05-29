/**
 * Problem: Counting Bits (LeetCode 338)
 * Time Complexity: O(N)
 * Memory Complexity: O(1) - No extra memory used
 */

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    (*returnSize) = n + 1;
    int* dp = (int*)calloc((*returnSize), sizeof(int));
    if (dp == NULL) return NULL;

    dp[0] = 0;
    int power = 1;

    for (int i = 1; i <= n; i++) {
        if (i == 2 * power)
            power *= 2;
        dp[i] = dp[i - power] + 1;
    }

    return dp;
}