/*
 * Problem: Coin Change (LeetCode 322)
 * Time Complexity: O(A x C) - A is amount and C is the number of coins for change
 * Memory Complexity: O(A)
 */

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        dp[i] = 10001;

    for (int i = 0; i < coinsSize; i++)
        for (int j = coins[i]; j <= amount; j++)
            dp[j] = (dp[j] <= dp[j - coins[i]] + 1) ? dp[j] : dp[j - coins[i]] + 1;

    return (dp[amount] == 10001) ? -1 : dp[amount];
}