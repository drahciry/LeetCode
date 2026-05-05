/*
 * Problem: Rotate List (LeetCode 61)
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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode dummy = {0, head};
    struct ListNode* current = &dummy;
    int size = 0;

    while (current->next) {
        size++;
        current = current->next;
    }

    int rotate = size - (k % size);
    if (rotate == size) return head;

    current->next = head;
    current = &dummy;
    for (int i = 0; i < rotate; i++)
        current = current->next;

    dummy.next = current->next;
    current->next = NULL;

    return dummy.next;
}