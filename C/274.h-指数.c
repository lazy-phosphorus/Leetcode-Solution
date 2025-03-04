/*
 * @lc app=leetcode.cn id=274 lang=c
 *
 * [274] H 指数
 */

#include <stdlib.h>

// @lc code=start

static int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int hIndex(int *citations, int citationsSize) {
    int h = 0;
    qsort(citations, citationsSize, sizeof(int), cmp);

    while (h < citationsSize) {
        if (citations[h] < h + 1) break;
        h++;
    }

    return h;
}
// @lc code=end
