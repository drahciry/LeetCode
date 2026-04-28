/*
 * Problem: Valid Anagram (LeetCode 242)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <string.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t))
        return false;

    int map[26];
    memset(map, 0, sizeof(map));

    for (int i = 0; s[i] != '\0'; i++) {
        map[s[i] - 'a']++;
        map[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (map[i] != 0)
            return false;

    return true;
}