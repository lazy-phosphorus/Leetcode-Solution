/*
 * @lc app=leetcode.cn id=2712 lang=rust
 *
 * [2712] 使所有字符相等的最小成本
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::{cmp::min, i64};

impl Solution {
    #[allow(dead_code)]
    pub fn minimum_cost(s: String) -> i64 {
        let mut result = i64::MAX;
        let mut pre_dp: Vec<[i64; 2]> = Vec::with_capacity(s.len() + 1);
        let mut suf_dp: Vec<[i64; 2]> = Vec::with_capacity(s.len() + 1);
        let chars: Vec<char> = s.chars().collect();

        let mut i = 0;
        while i < pre_dp.capacity() {
            pre_dp.push([0, 0]);
            suf_dp.push([0, 0]);
            i += 1;
        }

        let mut i = 0;
        while i < chars.len() {
            if chars[i] == '0' {
                pre_dp[i + 1][0] = pre_dp[i][0];
                pre_dp[i + 1][1] = pre_dp[i][0] + i as i64 + 1;
            } else {
                pre_dp[i + 1][0] = pre_dp[i][1] + i as i64 + 1;
                pre_dp[i + 1][1] = pre_dp[i][1];
            }
            i += 1;
        }

        let mut i = chars.len();
        while let Some(index) = i.checked_sub(1) {
            if chars[index] == '0' {
                suf_dp[index][0] = suf_dp[index + 1][0];
                suf_dp[index][1] = suf_dp[index + 1][0] + (chars.len() - index) as i64;
            } else {
                suf_dp[index][0] = suf_dp[index + 1][1] + (chars.len() - index) as i64;
                suf_dp[index][1] = suf_dp[index + 1][1];
            }
            i = index;
        }

        let mut i = 0;
        while i < pre_dp.len() {
            result = min(result, pre_dp[i][0] + suf_dp[i][0]);
            result = min(result, pre_dp[i][1] + suf_dp[i][1]);
            i += 1;
        }

        return result;
    }
}
// @lc code=end
