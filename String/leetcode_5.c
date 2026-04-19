/*
 * Problem: Logest Palindromic Substring (LeetCode 5)
 * Time Complexity: O(N²)
 * Memory Complexity: O(N)
 */

#include <stdlib.h>
#include <string.h>

int mid_to_border(char *s, int left, int right, int length) {
    while (left >= 0 && right < length && s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;
}

char* longestPalindrome(char* s) {
    if (s == NULL) return "";

    int length = strlen(s);
    if (length < 2) return s;

    int start = 0, end = 0;

    for (int i = 0; i < length; i++) {
        int len1 = mid_to_border(s, i, i, length);
        int len2 = mid_to_border(s, i, i + 1, length);

        int max_length = (len1 > len2) ? len1 : len2;

        if (max_length > (end - start)) {
            start = i - (max_length - 1) / 2;
            end = i + max_length / 2;
        }
    }

    int final_length = end - start + 1;
    char *result = (char*)malloc((final_length + 1) * sizeof(char));

    strncpy(result, s + start, final_length);
    result[final_length] = '\0';

    return result;
}