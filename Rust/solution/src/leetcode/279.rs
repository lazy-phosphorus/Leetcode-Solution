/*
 * @lc app=leetcode.cn id=279 lang=rust
 *
 * [279] 完全平方数
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::cmp::min;
impl Solution {
    #[allow(dead_code)]
    pub fn num_squares(n: i32) -> i32 {
        let mut dp: Vec<i32> = Vec::with_capacity(n as usize + 1);
        let mut nums: Vec<i32> = Vec::new();

        let mut i = 0;
        while i <= n {
            dp.push(i);
            i += 1;
        }

        i = 2;
        while i * i <= n {
            nums.push(i * i);
            i += 1;
        }

        for num in &nums {
            i = *num;
            while (i as usize) < dp.len() {
                let current = i as usize;
                let previous = (i - *num) as usize;
                dp[current] = min(dp[current], dp[previous] + 1);
                i += 1;
            }
        }

        return dp[n as usize];
    }
}
// @lc code=end
