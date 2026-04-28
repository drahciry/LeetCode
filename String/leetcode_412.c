/*
 * Problem: Fizz Buzz (LeetCode 412)
 * Time Complexity: O(N)
 * Memory Complexity: O(1) - The returned array is not useful for memory complexity extra evaluation
 */

#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** fizzBuzz(int n, int* returnSize) {
    char** answer = (char**)malloc(n * sizeof(char*));
    *returnSize = n;

    int cont3 = 1;
    int cont5 = 1;
    for (int i = 1; i <= n; i++) {
        answer[i - 1] = (char*)malloc(9 * sizeof(char));
        
        if (cont3 == 3 && cont5 == 5) {
            strcpy(answer[i - 1], "FizzBuzz");
            cont3 = 0;
            cont5 = 0;
        } else if (cont3 == 3) {
            strcpy(answer[i - 1], "Fizz");
            cont3 = 0;
        } else if (cont5 == 5) {
            strcpy(answer[i - 1], "Buzz");
            cont5 = 0;
        } else {
            sprintf(answer[i - 1], "%d", i);
        }

        cont3++;
        cont5++;
    }

    return answer;
}