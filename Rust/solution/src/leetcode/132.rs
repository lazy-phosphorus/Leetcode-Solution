/*
 * @lc app=leetcode.cn id=132 lang=rust
 *
 * [132] 分割回文串 II
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::cmp::min;

fn is_valid(s: &[char]) -> bool {
    let mut i = if s.len() % 2 == 0 {
        s.len() / 2
    } else {
        s.len() / 2 + 1
    };
    while i < s.len() {
        if s[i] != s[s.len() - i - 1] {
            return false;
        }
        i += 1;
    }
    return true;
}

impl Solution {
    #[allow(dead_code)]
    pub fn min_cut(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let mut dp: Vec<i32> = Vec::with_capacity(s.len() + 1);
        dp.resize(dp.capacity(), 0);

        let mut i = 1;
        dp[0] = -1;
        while i < chars.len() {
            let mut j = i;
            dp[i + 1] = dp[i] + 1;
            while let Some(index) = j.checked_sub(1) {
                if is_valid(&chars[index..i + 1]) {
                    dp[i + 1] = min(dp[i + 1], dp[index] + 1);
                }
                j = index;
            }
            i += 1;
        }

        return dp[s.len()];
    }
}
// @lc code=end
