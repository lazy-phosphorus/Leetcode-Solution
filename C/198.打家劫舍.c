/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int rob(int *nums, int numsSize) {
    int current_select = 0, previous_select = 0, current_ignore = 0,
        previous_ignore = 0;
    for (int i = 0; i < numsSize; i++) {
        current_select = previous_ignore + nums[i];
        current_ignore = max(previous_select, previous_ignore);
        previous_ignore = current_ignore;
        previous_select = current_select;
    }
    return max(current_select, current_ignore);
}
// @lc code=end
