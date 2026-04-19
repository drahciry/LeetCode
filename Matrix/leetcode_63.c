#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int rows = obstacleGridSize;
    int cols = obstacleGridColSize[0];
    if (obstacleGrid[0][0] == 1)
        return 0;

    int* dp = (int*)malloc(cols * sizeof(int));
    dp[0] = 1;
    for (int j = 1; j < cols; j++)
        if (obstacleGrid[0][j] == 0)
            dp[j] = dp[j - 1];
        else
            dp[j] = 0;

    for (int i = 1; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (obstacleGrid[i][j] == 1)
                dp[j] = 0;
            else if (j != 0)
                dp[j] = dp[j] + dp[j - 1];

    int result = dp[cols - 1];
    free(dp);
    return result;
}