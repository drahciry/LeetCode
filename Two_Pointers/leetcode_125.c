/*
 * Problem: Valid Palindrome (LeetCode 125)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <string.h>
#include <stdbool.h>

bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= '0' && c <= '9');
}

char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

bool isPalindrome(char* s) {
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j) {
        while (i < j && !isAlphanumeric(s[i])) i++;
        while (i < j && !isAlphanumeric(s[j])) j--;

        if (i < j && toLowercase(s[i]) != toLowercase(s[j]))
            return false;
        
        i++;
        j--;
    }

    return true;
}
