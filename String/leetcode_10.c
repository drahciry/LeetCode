/**
 * Problem: Regular Expression Matching (LeetCode 10)
 * Time Complexity: O(M x N) - M is the number of rows and N number of columns
 * Memory Complexity: O(N)
 */

#include <string.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int sLen = strlen(s);
    int pLen = strlen(p);

    bool prev[pLen + 1];
    memset(prev, 0, sizeof(prev));

    prev[0] = true;

    for (int j = 1; j <= pLen; j++)
        if (p[j - 1] == '*')
            prev[j] = prev[j - 2];

    for (int i = 1; i <= sLen; i++) {
        bool curr[pLen + 1];
        memset(curr, 0, sizeof(curr));

        for (int j = 1; j <= pLen; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                curr[j] = prev[j - 1];
            } else if (p[j - 1] == '*') {
                curr[j] = curr[j - 2];

                if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    curr[j] = (curr[j] || prev[j]) ? true : false;
            }
            prev[j - 1] = curr[j - 1];
        }
        prev[pLen] = curr[pLen];
    }

    return prev[pLen];
}