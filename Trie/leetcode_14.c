/*
 * Problem: Longest Common Prefix (LeetCode 14)
 * Solution with Trie
 * Time Complexity: O(N x K) - N is the size of biggest string and K is the number of strings
 * Memory Complexity: O(N x K)
 */

#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct Node {
    struct Node* children[ALPHABET_SIZE];
    bool isEnd;
} Node;

typedef struct {
    Node* root;
} Trie;

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node) {
        node->isEnd = false;
        memset(node->children, 0, sizeof(node->children));
    }
    return node;
}

void insert(Trie* trie, char* word) {
    Node* current = trie->root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            Node* child = createNode();
            current->children[index] = child;
        }
        current = current->children[index];
    }
    current->isEnd = true;
}

int getLongestCommonPrefix(Trie* trie) {
    Node* current = trie->root;
    int index = 0;

    while (current != NULL && current->isEnd == false) {
        int children = 0;
        int childIndex;
        for (int i = 0; i < ALPHABET_SIZE && children <= 1; i++)
            if (current->children[i] != NULL) {
                children++;
                childIndex = i;
            }
        if (children != 1) return index;
        index++;
        current = current->children[childIndex];
    }
    return index;
}

Trie* createTrie() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    if (trie) trie->root = createNode();

    return trie;
}

void deleteNode(Node* node) {
    if (node == NULL) return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i] != NULL)
            deleteNode(node->children[i]);

    free(node);
}

void deleteTrie(Trie* trie) {
    deleteNode(trie->root);
    free(trie);
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    Trie* trie = createTrie();
    for (int i = 0; i < strsSize; i++) insert(trie, strs[i]);
    int index = getLongestCommonPrefix(trie);
    deleteTrie(trie);

    strs[0][index] = '\0';
    return strs[0];
}

/*
 * Problem: Longest Common Prefix (LeetCode 14)
 * Vertical Scanning Solution
 * Time Complexity: O(N x K) - N is the size of smallest prefix and K is the number of strings
 * Memory Complexity: O(1)
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize < 1) return "";

    for (int j = 0; strs[0][j] != '\0'; j++)
        for (int i = 1; i < strsSize; i++)
            if (strs[i][j] == '\0' || strs[i][j] != strs[0][j]) {
                strs[0][j] = '\0';
                return strs[0];
            }

    return strs[0];
}