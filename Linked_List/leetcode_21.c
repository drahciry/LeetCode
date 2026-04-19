/*
 * Problem: Merge Two Sorted Lists (LeetCode 21)
 * Time Complexity: O(P) - P is the smallest size between list1 and list2
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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!(l1 || l2)) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct ListNode dummy;
    struct ListNode* current = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    current->next = (l1 != NULL) ? l1 : l2;

    return dummy.next;
}