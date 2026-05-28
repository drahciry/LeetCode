/**
 * Problem: Find the Length of the Longest Common Prefix (LeetCode 3043)
 * Time Complexity: O(M x D + N x D) -> O(M + N) - M is the arr1 size, 
 * N is the arr2 size and D is the biggest number of digits.
 * Memory Complexity: O(M x D) -> O(N)
 */

#include <stdlib.h>
#include <stdbool.h>

#define DIGITS 10

typedef struct Node {
    struct Node* nums[DIGITS];
    bool isEnd;
} Node;

typedef struct {
    Node* root;
} Trie;

Node* createNode() {
    Node* node = (Node*)calloc(1, sizeof(Node));
    return node;
}

void insert(Trie* trie, const char* num) {
    Node* current = trie->root;
    for (int i = 0; num[i] != '\0'; i++) {
        int index = num[i] - '0';
        if (current->nums[index] == NULL)
            current->nums[index] = createNode();
        current = current->nums[index];
    }
    current->isEnd = true;
}

int findLongestCommonPrefix(Trie* trie, const char* prefix) {
    Node* current = trie->root;

    int length = 0;
    for (int i = 0; current && prefix[i] != '\0'; i++) {
        int index = prefix[i] - '0';

        if (current->nums[index] == NULL) break;

        current = current->nums[index];
        length++;
    }

    return length;
}

Trie* createTrie() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    if (trie)
        trie->root = createNode();
    return trie;
}

void deleteNode(Node* node) {
    if (node == NULL) return;

    for (int i = 0; i < DIGITS; i++)
        if (node->nums[i] != NULL)
            deleteNode(node->nums[i]);
    free(node);
}

void deleteTrie(Trie* trie) {
    if (trie == NULL) return;

    deleteNode(trie->root);
    free(trie);
}

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    Trie* trie = createTrie();
    char buffer[12];

    for (int i = 0; i < arr1Size; i++) {
        snprintf(buffer, sizeof(buffer), "%d", arr1[i]);
        insert(trie, buffer);
    }

    int maxLength = 0;

    for (int i = 0; i < arr2Size; i++) {
        snprintf(buffer, sizeof(buffer), "%d", arr2[i]);
        int currentLength = findLongestCommonPrefix(trie, buffer);
        maxLength = max(maxLength, currentLength);
    }

    deleteTrie(trie);

    return maxLength;
}