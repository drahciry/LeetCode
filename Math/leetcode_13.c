/*
 * Problem: Roman To Integer (LeetCode 13)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <string.h>

int get_value(char symbol) {
    switch (symbol) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int romanToInt(char* s) {
    int total = 0;
    int last_value = 0;
    int length = strlen(s);

    for (int i = length - 1; i >= 0; i--) {
        int current_value = get_value(s[i]);

        if (current_value < last_value)
            total -= current_value;
        else
            total += current_value;

        last_value = current_value;
    }

    return total;
}