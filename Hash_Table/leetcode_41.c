/*
 * Problem: First Missing Positive (LeetCode 41)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;

    while (i < numsSize) {
        if (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            swap(&nums[i], &nums[nums[i] - 1]);
        } else i++;
    }

    for (int j = 0; j < numsSize; j++)
        if (nums[j] != j + 1)
            return j + 1;

    return numsSize + 1;
}