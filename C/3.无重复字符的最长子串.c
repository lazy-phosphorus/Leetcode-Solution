/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

#include <malloc.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

// @lc code=start

int lengthOfLongestSubstring(char *s) {
    size_t length = strlen(s);
    if (length == 0) return 0;

    char *queue = calloc(256, sizeof(char));
    int result = 0, head = 0, tail = 1;

    memset(queue, 0, 256 * sizeof(char));
    queue[head] = s[0];

    for (size_t i = 1; i < length; i++) {
        int j = 0;
        for (j = head; j != tail; j = (j + 1) % 256) {
            if (queue[j] == s[i]) {
                result = result > (tail + 256 - head) % 256
                             ? result
                             : (tail + 256 - head) % 256;
                head = (j + 1) % 256;
                break;
            }
        }
        queue[tail] = s[i];
        tail = (tail + 1) % 256;
    }

    result =
        result > (tail + 256 - head) % 256 ? result : (tail + 256 - head) % 256;

    free(queue);
    return result;
}
// @lc code=end
