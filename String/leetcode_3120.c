/**
 * Problem: Count the Number of Special Characters I
 * Time Complexity: O(N)
 * Memory Complexity: O(1)
 */

#include <string.h>
#include <stdbool.h>

bool isLower(char character) {
    return (character >= 'a' && character <= 'z');
}

bool isUpper(char character) {
    return (character >= 'A' && character <= 'Z');
}

char toLower(char character) {
    if (!isUpper(character))
        return character;
    return (character - 'A' + 'a');
}

char toUpper(char character) {
    if (!isLower(character))
        return character;
    return (character - 'a' + 'A');
}

int numberOfSpecialChars(char* word) {
    bool map[128];
    memset(map, false, sizeof(map));

    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (!map[word[i]] && isLower(word[i]) && map[toUpper(word[i])])
            count++;
        else if (!map[word[i]] && isUpper(word[i]) && map[toLower(word[i])])
            count++;
        
        map[word[i]] = true;
    }

    return count;
}