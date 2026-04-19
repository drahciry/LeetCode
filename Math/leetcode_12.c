/*
 * Problem: Integer to Roman (LeetCode 12)
 * Time Complexity: O(1)
 * Memory Complexity: O(1)
 */

#include <string.h>
#include <stdlib.h>

char* intToRoman(int num) {
    char* thousands[] = {"", "M", "MM", "MMM"};
    char* hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char* units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    char* result = (char*)malloc(16 * sizeof(char));
    result[0] = '\0';

    strcat(result, thousands[num / 1000]);
    strcat(result, hundreds[(num % 1000) / 100]);
    strcat(result, tens[(num % 100) / 10]);
    strcat(result, units[num % 10]);

    return result;
}