/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 */

#include <stdbool.h>

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int rob(int *nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int ignore_current = 0, select_current = 0, temp = 0, result = 0;
    for (int i = 1; i < numsSize; i++) {
        temp = max(select_current, ignore_current);
        select_current = ignore_current + nums[i];
        ignore_current = temp;
    }
    result = max(ignore_current, select_current);

    ignore_current = 0;
    select_current = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        temp = max(select_current, ignore_current);
        select_current = ignore_current + nums[i];
        ignore_current = temp;
    }
    temp = max(select_current, ignore_current);
    return max(result, temp);
}
// @lc code=end
