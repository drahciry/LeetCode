/*
 * Problem: Reverse Integer (LeetCode 7)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <limits.h>

int reverse(int x){
    int num = x;
    int reverseNum = 0;
    long long check;

    check = (long long) x;
    if (-1 * check > INT_MAX)
        return 0;

    if (x < 0)
        num *= -1;

    do {
        check = (long long) reverseNum * 10 + (num % 10);
        if (check > INT_MAX)
            return 0;
        if (-1 * check < INT_MIN)
            return 0;
        reverseNum = (reverseNum * 10) + (num % 10);
        num /= 10;
    } while (num > 0);

    if (x < 0)
        reverseNum *= -1;

    return reverseNum;
}