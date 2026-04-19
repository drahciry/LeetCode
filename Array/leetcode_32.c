/*
 * Problem: Longest Valid Parenthesis (LeetCode 32)
 * Solution with Stack
 * Time Complexity: O(N)
 * Memory Complexity: O(N)
 */

#include <stdlib.h>
#include <stdbool.h>

#define EMPTY -99

typedef struct {
    int* data;
    int size;
    int cap;
} Stack;

bool empty(Stack* stack) {
    return (stack->size == 0);
}

bool full(Stack* stack) {
    return (stack->size >= stack->cap);
}

void push(Stack* stack, int value) {
    if (full(stack)) return;
    stack->data[stack->size++] = value;
}

int pop(Stack* stack) {
    if (empty(stack)) return EMPTY;
    return stack->data[--stack->size];
}

int peek(Stack* stack) {
    if (empty(stack)) return EMPTY;
    return stack->data[stack->size - 1];
}

Stack* create_stack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack) {
        stack->size = 0;
        stack->cap = cap;
        stack->data = (int*)malloc(stack->cap * sizeof(int));
    }
    return stack;
}

void delete_stack(Stack* stack) {
    free(stack->data);
    free(stack);
}

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len <= 1) return 0;

    Stack* stack = create_stack(len);
    push(stack, -1);
    int longestValidSize = 0;
    int invalidTop = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            push(stack, i);
        } else if (pop(stack) != invalidTop) {
            longestValidSize = MAX(longestValidSize, i - peek(stack));
        } else {
            push(stack, i);
            invalidTop = i;
        }
    }

    delete_stack(stack);
    return longestValidSize;
}

/*
 * Problem: Longest Valid Parenthesis (LeetCode 32)
 * Dynamic Programming Solution
 * Time Complexity: O(N)
 * Memory Complexity: O(N)
 */

#include <stdlib.h>

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len <= 1) return 0;

    int* dp = (int*)calloc(len, sizeof(int));
    int idx;
 
    if (s[0] == '(' && s[1] == ')') dp[1] = 2;
    int longestValidSize = dp[1];
    for (int i = 2; i < len; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(')
                dp[i] = 2 + dp[i - 2];
            else if ((idx = i - dp[i - 1] - 1) >= 0 && s[idx] == '(')
                dp[i] = 2 + dp[i - 1] + dp[MAX(idx - 1, 0)];
            longestValidSize = MAX(longestValidSize, dp[i]);
        }
    }

    free(dp);
    return longestValidSize;
}