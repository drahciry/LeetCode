/**
 * Problem: Edit Distance (LeetCode 72)
 * Time Complexity: O(M x N) - M is the word1 size and N is the word2 size
 * Memory Complexity: O(N) - Dynamic Programming Otimization
 */

#include <stdlib.h>

int min3(int a, int b, int c) {
    int min = (a < b) ? a : b;
    return (min < c) ? min : c;
}

void swap(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int minDistance(char* word1, char* word2) {
    int word1Size = strlen(word1);
    int word2Size = strlen(word2);

    if (word1Size == 0)
        return word2Size;
    else if (word2Size == 0)
        return word1Size;

    int* prev = (int*)malloc((word2Size + 1) * sizeof(int));
    int* curr = (int*)malloc((word2Size + 1) * sizeof(int));

    for (int j = 0; j <= word2Size; j++)
        prev[j] = j;

    for (int i = 1; i <= word1Size; i++) {
        curr[0] = i;

        for (int j = 1; j <= word2Size; j++) {
            if (word1[i - 1] == word2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min3(prev[j], curr[j - 1], prev[j - 1]);
            prev[j - 1] = curr[j - 1];
        }

        swap(&prev, &curr);
    }

    int answer = prev[word2Size];

    free(prev);
    free(curr);

    return answer;
}