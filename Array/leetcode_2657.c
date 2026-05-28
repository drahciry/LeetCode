/**
 * Problem: Find the Prefix Common Array of Two Arrays (LeetCode 2657)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <stdint.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

uint64_t setBit(uint64_t map, int i) {
    return map | (1UL << i);
}

bool checkBit(uint64_t map, int i) {
    return ((map & (1UL << i)) != 0);
}

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    uint64_t map = 0UL;

    int* C = (int*)calloc(ASize, sizeof(int));
    if (C == NULL) return NULL;

    (*returnSize) = ASize;
    int commonCount = 0;

    for (int i = 0; i < ASize; i++) {
        if (checkBit(map, A[i] - 1))
            commonCount++;
        map = setBit(map, A[i] - 1);

        if (checkBit(map, B[i] - 1))
            commonCount++;
        map = setBit(map, B[i] - 1);

        C[i] = commonCount;
    }

    return C;
}