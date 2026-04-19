/*
 * Problem: Remove Nth Node From End of List (LeetCode 19)
 * Time Complexity: O(M) - M is the list size
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* node_to_remove = slow->next;
    slow->next = node_to_remove->next;
    free(node_to_remove);

    return dummy.next;
}