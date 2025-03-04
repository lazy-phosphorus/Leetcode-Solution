/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */

#include <stdbool.h>

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

bool canJump(int *nums, int numsSize) {
    int reach = nums[0], prev_reach = 0, step = 0;

    while (prev_reach < reach && reach < numsSize - 1) {
        step = 0;
        for (int i = prev_reach + 1; i <= reach; i++) {
            step = max(i + nums[i], step);
        }
        prev_reach = reach;
        reach = max(step, reach);
    }

    return reach >= numsSize - 1;
}
// @lc code=end
