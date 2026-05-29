/**
 * Problem: Reverse Nodes in k-Group (LeetCode 25)
 * Time Complexity: O(N x k)
 * Memory Complexity: O(1)
 */

#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;

    int count = 0;
    struct ListNode* curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prevGroupEnd = &dummy;

    for (; count >= k; count -= k) {
        struct ListNode* groupStart = prevGroupEnd->next;
        curr = groupStart;
        struct ListNode* prev = NULL;
        struct ListNode* next = NULL;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        prevGroupEnd->next = prev;
        groupStart->next = curr;

        prevGroupEnd = groupStart;
    }

    return dummy.next;
}