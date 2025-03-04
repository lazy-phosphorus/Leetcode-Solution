/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

#include <malloc.h>
#include <stddef.h>
#include <string.h>

// @lc code=start
char *convert(char *s, int numRows) {
    if (numRows == 1) return s;
    int t = 2 * numRows - 2;
    size_t length = strlen(s);
    char *result = calloc(length + 1, sizeof(char));

    int p = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= length / t; j++) {
            if (j * t + i < length) {
                result[p] = s[j * t + i];
                p++;
            }
            if (i != 0 && i != numRows - 1 && j * t + t - i < length) {
                result[p] = s[j * t + t - i];
                p++;
            }
        }
    }

    result[length] = '\0';
    return result;
}
// @lc code=end
