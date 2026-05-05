/**
 * Problem: Copy List with Random Pointer (LeetCode 138)
 * Time Complexity: O(N)
 * Memory Complexity: O(1) - The answer doesn't must be counted because is the answer
 */

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* current = head;
    struct Node* copyNode;
    while (current) {
        copyNode = (struct Node*)malloc(sizeof(struct Node));

        copyNode->next = current->next;
        copyNode->val = current->val;
        copyNode->random = NULL;

        current->next = copyNode;
        current = copyNode->next;
    }

    current = head;
    while (current) {
        if (current->random)
            current->next->random = current->random->next;

        current = current->next->next;
    }

    current = head;
    struct Node* copyHead = head->next;

    while (current) {
        copyNode = current->next;
        current->next = copyNode->next;

        if (current->next)
            copyNode->next = current->next->next;

        current = current->next;
    }

    return copyHead;
}