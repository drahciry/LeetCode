/*
 * Problem: Divide Two Integers (LeetCode 29)
 * Time Complexity: O(log N) - N is the divisor
 * Memory Complexity: O(1)
 */

#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    unsigned long a = labs(dividend);
    unsigned long b = labs(divisor);
    unsigned long result = 0;

    while (a >= b) {
        unsigned long temp = b;
        unsigned long multiple = 1;

        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        result += multiple;
    }

    if ((dividend < 0) ^ (divisor < 0)) result = -result;

    return (int)result;
}