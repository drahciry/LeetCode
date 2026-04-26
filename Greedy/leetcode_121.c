/*
 * Problem: Best Time to Buy and Sell Stock (LeetCode 121)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

int maxProfit(int* prices, int pricesSize) {
    int min_price = 10001;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        int sub = prices[i] - min_price;
        if (prices[i] < min_price)
            min_price = prices[i];
        else if (sub > max_profit)
            max_profit = sub;
    }

    return max_profit;
}
