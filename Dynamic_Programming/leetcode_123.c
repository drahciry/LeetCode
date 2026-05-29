/**
 * Problem: Best Time to Buy and Sell Stock III (LeetCode 123)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int buy1 = -100001;
    int sell1 = 0;
    int buy2 = -100001;
    int sell2 = 0;

    for (int i = 0; i < pricesSize; i++) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }

    return sell2;
}