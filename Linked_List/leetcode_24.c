/*
 * Problem: Swap Node in Pairs (LeetCode 24)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode dummy = {0, head};

    while (head && head->next) {
        swap(&head->val, &head->next->val);
        head = head->next->next;
    }

    return dummy.next;
}