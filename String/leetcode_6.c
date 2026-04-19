/*
 * Problem: Zigzag Conversion (LeetCode 6)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <stdlib.h>

char* convert(char* s, int numRows) {
    if (s == NULL)
        return "";

    int size = strlen(s);
    if (size < 2)
        return s;

    int index = 0;
    int tier = 0;
    int i = 0;

    char *zigzag = malloc((size + 1) * sizeof(char));

    while ((tier < numRows) && (i < size) && (numRows != 1)) {
        zigzag[i++] = s[index];
        index += 2 * (numRows - 1);
        if ((tier != 0) && (tier != numRows - 1))
            if (index - 2 * tier < size)
                zigzag[i++] = s[index - 2 * tier];
        if (index >= size)
            index = ++tier;
    }
    for (i = 0; (i < size) && (numRows == 1); i++)
        zigzag[i] = s[i];
    zigzag[size] = '\0';

    return zigzag;
}