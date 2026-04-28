/*
 * Problem: Reverse String (LeetCode 344)
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char* s, int sSize) {
    int i = 0;
    int j = sSize - 1;

    while (i < j) {
        swap(s + i, s + j);
        i++;
        j--;
    }
}