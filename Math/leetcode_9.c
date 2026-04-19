/*
 * Problem: Palindrome Number (LeetCode 9)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int half_reverse = 0;

    while (x > half_reverse) {
        half_reverse = (half_reverse * 10) + (x % 10);
        x /= 10;
    }

    return half_reverse == x || half_reverse / 10 == x;
}