/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int* solution = (int*)malloc((*returnSize) * sizeof(int));
    solution[0] = -1;
    solution[1] = -1;

    int i = 0;
    int j = numbersSize - 1;

    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            solution[0] = i + 1;
            solution[1] = j + 1;
            return solution;
        } else if (sum > target) {
            j--;
        } else {
            i++;
        }
    }

    return solution;
}