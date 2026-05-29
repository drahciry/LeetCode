/**
 * Problem: Best Time to Buy and Sell Stock IV (LeetCode 188)
 * Time Complexity: Best Case (no limits) - O(N) | Worst Case (at most k transactions) - O(N x k)
 * Memory Complexity: O(1) | O(k)
 */

#include <stdlib.h>

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProfitII(int* prices, int pricesSize) {
    int minPrice = 1001;
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > 0) {
            maxProfit += (prices[i] - minPrice);
            minPrice = prices[i];
        }
    }

    return maxProfit;
}

int maxProfit(int k, int* prices, int pricesSize) {
    if (k >= (pricesSize >> 1))
        return maxProfitII(prices, pricesSize);

    int* buy = (int*)malloc(k * sizeof(int));
    if (buy == NULL) return 0;

    int* sell = (int*)calloc(k, sizeof(int));
    if (sell == NULL) {
        free(buy);
        return 0;
    }

    for (int i = 0; i < k; i++)
        buy[i] = -1001;

    for (int i = 0; i < pricesSize; i++) {
        buy[0] = max(buy[0], -prices[i]);
        sell[0] = max(sell[0], buy[0] + prices[i]);

        for (int j = 1; j < k; j++) {
            buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            sell[j] = max(sell[j], buy[j] + prices[i]);
        }
    }

    int answer = sell[k - 1];

    free(buy);
    free(sell);

    return answer;
}