#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int num = x;
    int reverse = 0;
    long long check;

    do {
        check = (long long) reverse * 10 + num % 10;
        if (check >= INT_MAX)
            return false;
        reverse = (reverse * 10) + (num % 10);
        num /= 10; 
    } while (num > 0);

    return (reverse == x);
}