/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

char** letterCombinations(char* digits, int* returnSize) {
    char* map[] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    int length = strlen(digits);
    if (length == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 1;
    for (int i = 0; i < length; i++) 
        (*returnSize) *= strlen(map[digits[i] - '0']);

    char** result = (char**)malloc((*returnSize) * sizeof(char*));
    for (int i = 0; i < (*returnSize); i++) 
        result[i] = (char*)malloc((length + 1) * sizeof(char));

    int block_size = (*returnSize);
    for (int j = 0; j < length; j++) {
        char* letters = map[digits[j] - '0'];
        int letters_length = strlen(letters);
        block_size /= letters_length;

        for (int i = 0; i < (*returnSize); i++)
            result[i][j] = letters[(i / block_size) % letters_length];
    }

    for (int i = 0; i < (*returnSize); i++)
        result[i][length] = '\0';

    return result;
}