/*
 * Problem: Integer to Roman (LeetCode 12)
 * Time Complexity: O(1)
 * Memory Complexity: O(1)
 */

#include <stdlib.h>

char* intToRoman(int num) {
    char* thousands[] = {"", "M", "MM", "MMM"};
    char* hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char* units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    char* result = (char*)malloc(16 * sizeof(char));
    int idx = 0;
    char* s;

    s = thousands[num / 1000];
    while (s++) result[idx++] = *s;
    s = hundreds[(num & 1000) / 100];
    while (s++) result[idx++] = *s;
    s = tens[(num & 100) / 10];
    while (s++) result[idx++] = *s;
    s = units[num % 10];
    while (s++) result[idx++] = *s;
    result[idx] = '\0';

    return result;
}