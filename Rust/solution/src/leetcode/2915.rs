/*
 * @lc app=leetcode.cn id=2915 lang=rust
 *
 * [2915] 和为目标值的最长子序列的长度
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::{cmp::max, i32};
impl Solution {
    #[allow(dead_code)]
    pub fn length_of_longest_subsequence(nums: Vec<i32>, target: i32) -> i32 {
        let mut dp: Vec<i32> = Vec::with_capacity(target as usize + 1);
        while dp.len() <= target as usize {
            dp.push(i32::MIN);
        }
        dp[0] = 0;
        for num in &nums {
            let mut some_i = dp.len().checked_sub(1);
            while let Some(i) = some_i {
                if i < *num as usize {
                    break;
                }
                if dp[i - *num as usize] != i32::MIN {
                    dp[i] = max(dp[i - *num as usize] + 1, dp[i]);
                }
                some_i = i.checked_sub(1);
            }
        }

        return if dp[target as usize] == i32::MIN {
            -1
        } else {
            dp[target as usize]
        };
    }
}
// @lc code=end
