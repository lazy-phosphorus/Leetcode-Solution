/*
 * @lc app=leetcode.cn id=377 lang=rust
 *
 * [377] 组合总和 Ⅳ
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let mut dp: Vec<i32> = Vec::with_capacity(target as usize + 1);

        let mut i = 0;
        while i < dp.capacity() {
            dp.push(0);
            i += 1;
        }
        dp[0] = 1;

        let mut i = 1;
        while i <= target as usize {
            let mut j = 0;
            while j < nums.len() {
                if i >= nums[j] as usize {
                    dp[i] += dp[i - nums[j] as usize];
                }
                j += 1;
            }
            i += 1;
        }
        return dp[target as usize];
    }
}
// @lc code=end
