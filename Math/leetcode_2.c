/*
 * Problem: Add Two Numbers (LeetCode 2)
 * Time Complexity: O(M + N) - M is the list1 size and N list2 size
 * Memory Complexity: O(M + N)
 */

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
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *sum_list = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *current_sum = sum_list;
    int carry = 0;

    sum_list->val = 0;
    sum_list->next = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = (sum / 10);
        
        current_sum->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current_sum = current_sum->next;

        current_sum->val = (sum % 10);
        current_sum->next = NULL;
    }

    return sum_list->next;
}