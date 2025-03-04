/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int jump(int *nums, int numsSize) {
    if (numsSize == 1) return 0;
    int reach = nums[0], prev_reach = 0, next_reach = 0, step = 0;

    while (reach > prev_reach && reach < numsSize - 1) {
        next_reach = 0;
        for (int i = prev_reach + 1; i <= reach; i++) {
            next_reach = max(i + nums[i], next_reach);
        }
        step++;
        prev_reach = reach;
        reach = next_reach;
    }
    return step + 1;
}
// @lc code=end
