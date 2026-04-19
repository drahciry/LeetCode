/*
 * Problem: Valid Parenthesis (LeetCode 20)
 * Time Complexity: O(N)
 * Memory Complexity: O(N)
 */

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* data;
    int top;
    int cap;
} Stack;

Stack* create_stack(int cap) {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    s->cap = cap;
    s->top = -1;
    s->data = (char*)malloc(cap * sizeof(char));

    return s;
}

bool empty(Stack* s) {
    return (s->top == -1);
}

void push(Stack* s, char data) {
    if (s->top == (s->cap - 1))
        return;
    s->top++;
    s->data[s->top] = data;
}

char pop(Stack* s) {
    if (empty(s)) return '\0';
    return s->data[(s->top)--];
}

void delete_stack(Stack* s) {
    free(s->data);
    free(s);
}

bool matches(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isValid(char* s) {
    int length = strlen(s);
    Stack* stack = create_stack(length);

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(stack, s[i]);
        } else {
            if (empty(stack) || !matches(pop(stack), s[i])) {
                delete_stack(stack);
                return false;
            }
        }
    }
    bool result = empty(stack);
    delete_stack(stack);
    return result;
}