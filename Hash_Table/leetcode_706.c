/**
 * Problem: Design HashMap (LeetCode 706)
 * Time Complexity: O(1) - On average
 * Memory Complexity: O(N) - Grows with input
 */

#include <stdlib.h>
#include <stdbool.h>

const inline int baseCapacity = 100;

typedef struct Node {
    int key;
    int item;
    struct Node* next;
} Node;

typedef struct {
    Node** table;
    int R;
    int size;
    int capacity;
} MyHashMap;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int divisor = 2; divisor * divisor <= num; divisor++)
        if (num % divisor == 0)
            return false;
    return true;
}

int primeBefore(int num) {
    int prime = num - 1;
    while (prime > 2 && !isPrime(prime))
        prime--;
    return (prime > 2) ? prime : 2;
}

int primeAfter(int num) {
    int prime = num + 1;
    while (!isPrime(prime))
        prime++;
    return prime;
}

Node* nodeCreate(int key, int item) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node) {
        node->key = key;
        node->item = item;
        node->next = NULL;
    }
    return node;
}

void linkedListFree(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

bool putLinkedList(Node** node, int key, int item) {
    bool newNode = false;
    Node** current = node;

    while (*current && (*current)->key != key)
        current = &((*current)->next);

    if (*current == NULL) {
        Node* new_node = nodeCreate(key, item);
        *current = new_node;
        newNode = true;
    } else (*current)->item = item;

    return newNode;
}

bool removeLinkedList(Node** node, int key) {
    Node** current = node;

    while (*current && (*current)->key != key)
        current = &((*current)->next);

    if (*current == NULL) return false;

    Node* target = *current;
    *current = target->next;
    free(target);
    return true;
}

Node* getLinkedList(Node* node, int key) {
    Node* current = node;

    while (current && current->key != key)
        current = current->next;

    return current;
}

int hashInt(MyHashMap* obj, int key) {
    unsigned int h = (unsigned int)key;

    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;

    return h % obj->capacity;
}

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    if (obj) {
        obj->size = 0;
        obj->capacity = primeAfter(baseCapacity);
        obj->R = primeBefore(obj->capacity);
        obj->table = (Node**)calloc(obj->capacity, sizeof(Node*));
    }
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value);

void rehash(MyHashMap* obj) {
    int oldCapacity = obj->capacity;
    int newCapacity = primeAfter(oldCapacity * 2);

    Node** oldTable = obj->table;
    Node** newTable = (Node**)calloc(newCapacity, sizeof(Node*));
    if (newTable == NULL) return;

    obj->size = 0;
    obj->table = newTable;
    obj->capacity = newCapacity;
    obj->R = primeBefore(newCapacity);

    for (int i = 0; i < oldCapacity; i++) {
        if (oldTable[i] == NULL) continue;

        Node* current = oldTable[i];
        while (current) {
            Node* next = current->next;
            int key = current->key;
            int item = current->item;
            myHashMapPut(obj, key, item);
            free(current);
            current = next;
        }
    }

    free(oldTable);
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    double loadFactor = (double) obj->size / obj->capacity;
    if (loadFactor >= 0.7) rehash(obj);

    int hash = hashInt(obj, key);
    if (putLinkedList(&(obj->table[hash]), key, value))
        obj->size++;
}

int myHashMapGet(MyHashMap* obj, int key) {
    if (obj->size <= 0) return -1;

    int hash = hashInt(obj, key);
    Node* target = getLinkedList(obj->table[hash], key);

    if (target)
        return target->item;
    else
        return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    if (obj->size <= 0) return;

    int hash = hashInt(obj, key);
    if (removeLinkedList(&(obj->table[hash]), key))
        obj->size--;
}

void myHashMapFree(MyHashMap* obj) {
    if (obj) {
        for (int i = 0; i < obj->capacity; i++)
            linkedListFree(obj->table[i]);
        free(obj->table);
        free(obj);
    }
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/