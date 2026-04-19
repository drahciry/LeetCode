/*
 * Problem: Find the Index of the First Occurence in String (LeetCode 28)
 * Time Complexity: O(H x N)
 * Memory Complexity: O(1)
 */

#include <string.h>

int strStr(char* haystack, char* needle) {
    int h = strlen(haystack);
    int n = strlen(needle);

    if (h < n) return -1;

    for (int i = 0; i <= (h - n); i++) {
        int j = 0;

        while (j < n && haystack[i + j] == needle[j]) j++;

        if (j == n) return i;
    }

    return -1;
}