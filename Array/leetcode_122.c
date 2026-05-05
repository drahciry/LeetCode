/**
 * Problem: Best Time to Buy and Sell Stock II (LeetCode 122)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

int maxProfit(int* prices, int pricesSize) {
    int min_price = 30001;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_price)
            min_price = prices[i];
        else if (prices[i] - min_price > 0) {
            max_profit += prices[i] - min_price;
            min_price = prices[i];
        }
    }

    return max_profit;
}