/*
 * Problem: Merge k Sorted Lists (LeetCode 23)
 * Time Complexity: O(N log K) - N is the sum of lists sizes and K is the number of lists
 * Memory Complexity: O(K)
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

typedef struct {
    struct ListNode** nodes;
    int size;
    int cap;
} MinHeap;

void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->nodes[idx]->val < heap->nodes[parent]->val) {
            swap(&heap->nodes[idx], &heap->nodes[parent]);
            idx = parent;
        } else break;
    }
}

void heapify_down(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    if (left < heap->size && heap->nodes[left]->val < heap->nodes[smallest]->val)
        smallest = left;
    if (right < heap->size && heap->nodes[right]->val < heap->nodes[smallest]->val)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->nodes[idx], &heap->nodes[smallest]);
        heapify_down(heap, smallest);
    }
}

void push(MinHeap* heap, struct ListNode* node) {
    if (!node) return;
    heap->nodes[heap->size] = node;
    heapify_up(heap, heap->size);
    heap->size++;
}

struct ListNode* pop(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    struct ListNode* root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);
    return root;
}

MinHeap* create_heap(int cap) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    if (!heap) return NULL;
    heap->size = 0;
    heap->cap = cap;
    heap->nodes = (struct ListNode**)malloc(heap->cap * sizeof(struct ListNode*));

    return heap;
}

void delete_heap(MinHeap* heap) {
    free(heap->nodes);
    free(heap);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    MinHeap* heap = create_heap(listsSize);
    struct ListNode dummy = {0, NULL};
    struct ListNode* current = &dummy;

    for (int i = 0; i < listsSize; i++)
        push(heap, lists[i]);

    while (heap->size != 0) {
        current->next = pop(heap);
        current = current->next;
        if (current->next) 
            push(heap, current->next);
    }

    delete_heap(heap);

    return dummy.next;
}