/*
 * Problem: Contains Duplicate (LeetCode 217)
 * Time Complexity: O(N)
 * Memory Complexity: O(N)
 */

#include <stdlib.h>
#include <stdbool.h>

#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2

typedef struct {
    int* keys;
    char* status;
    int R;
    int size;
    int inserteds;
} HashTable;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int divisor = 2; divisor * divisor <= num; divisor++)
        if (num % divisor == 0)
            return false;
    return true;
}

int primeBefore(int num) {
    int prime = num - 1;
    while (prime > 2) {
        if (isPrime(prime))
            return prime;
        prime--;
    }
    return 2;
}

int primeAfter(int num) {
    int prime = num + 1;
    while (true) {
        if (isPrime(prime))
            return prime;
        prime++;
    }
}

unsigned int hash1(HashTable* hash_table, int key) {
    return (hash_table == NULL) ? 0 : ((unsigned int)key % hash_table->size);
}

unsigned int hash2(HashTable* hash_table, int key) {
    return (hash_table == NULL) ? 0 : (hash_table->R - ((unsigned int)key % hash_table->R));
}

unsigned int doubleHash(HashTable* hash_table, int key, int attempt) {
    return ((hash1(hash_table, key) + attempt * hash2(hash_table, key)) % hash_table->size);
}

void insertItem(HashTable* hash_table, int key) {
    if (hash_table == NULL || hash_table->inserteds >= hash_table->size) return;

    unsigned int hash;
    unsigned int deletedHash = -1;
    for (int attempt = 0; attempt < hash_table->size; attempt++) {
        hash = doubleHash(hash_table, key, attempt);
        if (hash_table->status[hash] == EMPTY) {
            break;
        } else if (hash_table->status[hash] == OCCUPIED) {
            if (hash_table->keys[hash] == key) return;
        } else if (hash_table->status[hash] == DELETED && deletedHash == -1) {
            deletedHash = hash;
        }
    }

    if (deletedHash != -1)
        hash = deletedHash;

    hash_table->keys[hash] = key;
    hash_table->status[hash] = OCCUPIED;
    hash_table->inserteds++;
}

void deleteItem(HashTable* hash_table, int key) {
    if (hash_table == NULL) return;

    for (int attempt = 0; attempt < hash_table->size; attempt++) {
        unsigned int hash = doubleHash(hash_table, key, attempt);
        if (hash_table->status[hash] == EMPTY) {
            return;
        } else if (hash_table->status[hash] == OCCUPIED && hash_table->keys[hash] == key) {
            hash_table->status[hash] = DELETED;
            hash_table->inserteds--;
        }
    }
}

bool getItem(HashTable* hash_table, int key) {
    if (hash_table == NULL) return false;

    for (int attempt = 0; attempt < hash_table->size; attempt++) {
        unsigned int hash = doubleHash(hash_table, key, attempt);
        if (hash_table->status[hash] == EMPTY)
            return false;
        else if (hash_table->status[hash] == OCCUPIED && hash_table->keys[hash] == key)
            return true;
    }
    return false;
}

HashTable* create_table(int initSize) {
    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
    if (hash_table) {
        hash_table->size = primeAfter(initSize * 2);
        hash_table->R = primeBefore(hash_table->size);
        hash_table->inserteds = 0;
        hash_table->keys = (int*)malloc(hash_table->size * sizeof(int));
        hash_table->status = (char*)calloc(hash_table->size, sizeof(char));
    }
    return hash_table;
}

void delete_table(HashTable* hash_table) {
    free(hash_table->keys);
    free(hash_table->status);
    free(hash_table);
}

bool containsDuplicate(int* nums, int numsSize) {
    HashTable* hash_table = create_table(numsSize);

    for (int i = 0; i < numsSize; i++) {
        if (getItem(hash_table, nums[i])) {
            delete_table(hash_table);
            return true;
        }
        insertItem(hash_table, nums[i]);
    }

    delete_table(hash_table);
    return false;
}
