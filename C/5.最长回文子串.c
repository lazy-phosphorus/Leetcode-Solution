/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <malloc.h>
#include <stddef.h>
#include <string.h>

char *longestPalindrome(char *s) {
    size_t length = strlen(s);
    char *result = NULL;

    size_t start = 0, end = 1, i = 0;

    while (i < length) {
        size_t j = 1;
        for (; j < length - i && j <= i + 1; j++) {
            if (s[i + j] != s[i - j + 1]) break;
        }
        if ((j - 1) * 2 > end - start) {
            start = i - j + 2;
            end = i + j;
        }
        size_t k = 1;
        for (; k < length - i && k <= i; k++) {
            if (s[i + k] != s[i - k]) break;
        }
        if (k * 2 - 1 > end - start) {
            start = i - k + 1;
            end = i + k;
        }

        i++;
    }

    result = calloc(end - start + 1, sizeof(char));
    memcpy(result, s + start, end - start);
    result[end - start] = '\0';
    return result;
}
// @lc code=end
