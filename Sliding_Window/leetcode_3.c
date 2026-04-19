#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    if (length == 0)
        return 0;

    int char_map[95];
    memset(char_map, -1, sizeof(char_map));

    int max_length = 0;
    int start = 0;

    for (int end = 0; end < length; end++) {
        if (char_map[s[end] - 32] >= start)
            start = char_map[s[end] - 32] + 1;

        char_map[s[end] - 32] = end;

        max_length = (max_length > end - start + 1) ? max_length : (end - start + 1);
    }

    return max_length;
}