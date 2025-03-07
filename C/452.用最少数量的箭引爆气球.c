/*
 * @lc app=leetcode.cn id=452 lang=c
 *
 * [452] 用最少数量的箭引爆气球
 */

#include <stdlib.h>

// @lc code=start
static inline int cmp(const void *a, const void *b) {
    return (*(int **)a)[1] > (*(int **)b)[1];
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
    int result = 0;

    qsort(points, pointsSize, sizeof(int *), cmp);

    int i = 0;
    while (i < pointsSize) {
        int j = i + 1;
        result++;
        while (j < pointsSize && points[j][0] <= points[i][1]) {
            j++;
        }
        i = j;
    }
    return result;
}
// @lc code=end
