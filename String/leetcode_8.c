#include <limits.h>
#include <stddef.h>

int myAtoi(char* s) {
    if (!s) return 0;

    int result = 0;
    int sign = 1;
    char* p = s;

    while (*p == ' ') p++;

    if (*p == '-' || *p == '+') {
        sign = (*p == '-') ? -1 : 1;
        p++;
    }

    while (*p >= '0' && *p <= '9') {
        int digit = *p - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
            return (sign == 1) ? INT_MAX : INT_MIN;
        result = result * 10 + digit;
        p++;
    }

    return result * sign;
}