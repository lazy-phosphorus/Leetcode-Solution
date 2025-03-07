/*
 * @lc app=leetcode.cn id=435 lang=c
 *
 * [435] 无重叠区间
 */

#include <limits.h>
#include <stdlib.h>

// @lc code=start

static inline int cmp(const void *a, const void *b) {
    return (*(int **)a)[1] - (*(int **)b)[1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize,
                          int *intervalsColSize) {
    int result = 0, right = INT_MIN;

    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    for (int i = 0; i < intervalsSize; i++) {
        if (right <= intervals[i][0]) {
            right = intervals[i][1];
        } else {
            result++;
        }
    }

    return result;
}
// @lc code=end
