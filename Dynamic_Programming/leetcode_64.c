/*
 * Problem: Minimum Path Sum (LeetCode 64)
 * Time Complexity: O(M x N) - M is the number of rows and N number of columns
 * Memory Complexity: O(N) - State Compression
 */

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int* dp = (int*)malloc(cols * sizeof(int));
    dp[0] = grid[0][0];
    for (int col = 1; col < cols; col++)
        dp[col] = grid[0][col] + dp[col - 1];

    for (int row = 1; row < rows; row++) {
        dp[0] += grid[row][0];
        for (int col = 1; col < cols; col++) {
            dp[col] = MIN(dp[col - 1], dp[col]) + grid[row][col];
        }
    }

    int result = dp[cols - 1];
    free(dp);
    return result;
}