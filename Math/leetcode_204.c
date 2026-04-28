/*
 * Problem: Count Primes (LeetCode 204)
 * Time Complexity: O(N log log N) - Sum of the reciprocals of prime numbers x N
 * Memory Complexity: O(N)
 */

#include <stdlib.h>
#include <stdbool.h>

int countPrimes(int n) {
    if (n <= 2) return 0;

    bool* is_prime = (bool*)malloc(n * sizeof(bool));
    memset(is_prime, true, n * sizeof(bool));

    is_prime[0] = false;
    is_prime[1] = false;

    int count = 0;

    for (int p = 2; p * p < n; p++)
        if (is_prime[p])
            for (int i = p * p; i < n; i += p)
                is_prime[i] = false;

    for (int i = 0; i < n; i++)
        if (is_prime[i]) count++;

    free(is_prime);
    return count;
}