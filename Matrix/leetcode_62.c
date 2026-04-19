/*
 * Problem: Unique Paths (LeetCode 62)
 * Time Complexity: O(M x N)
 * Memory Complexity: O(N) - State Compression
 */

#include <stdlib.h>

int uniquePaths(int m, int n) {
    int* dp = (int*)malloc(n* sizeof(int));
    dp[0] = 1;
    for (int j = 1; j < n; j++)
        dp[j] = 1;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[j] = dp[j] + dp[j - 1];
    
    int result = dp[n - 1];
    free(dp);
    return result;
}