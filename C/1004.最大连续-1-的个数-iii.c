/*
 * @lc app=leetcode.cn id=1004 lang=c
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
int longestOnes(int *nums, int numsSize, int k) {
    int left = 0, right = 0, k_cache = k;

    while (right < numsSize) {
        if (nums[right] == 0) {
            if (k_cache > 0)
                k_cache--;
            else if (nums[left] == 0)
                left++;
            else {
                k_cache--;
                left++;
            }
        } else if (k_cache < 0) {
            if (nums[left] == 0) k_cache++;
            left++;
        }

        right++;
    }
    return right - left;
}
// @lc code=end
