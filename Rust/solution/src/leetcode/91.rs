/*
 * @lc app=leetcode.cn id=91 lang=rust
 *
 * [91] 解码方法
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
#[allow(dead_code)]
fn is_bind(ch: char) -> bool {
    return ch == '0';
}

#[allow(dead_code)]
fn is_misleading(prev: char, ch: char) -> bool {
    return prev == '1' || (prev == '2' && ch <= '6');
}

#[allow(dead_code)]
fn is_invalid(prev: char, ch: char) -> bool {
    return ch == '0' && prev != '1' && prev != '2';
}

impl Solution {
    #[allow(dead_code)]
    pub fn num_decodings(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let mut dp: Vec<i32> = Vec::with_capacity(s.len() + 1);
        dp.resize(dp.capacity(), 0);

        if chars[0] == '0' {
            return 0;
        }
        dp[0] = 1;
        dp[1] = 1;

        let mut i = 1;
        while i < chars.len() {
            if is_invalid(chars[i - 1], chars[i]) {
                return 0;
            }
            dp[i + 1] = if is_bind(chars[i]) {
                dp[i - 1]
            } else if is_misleading(chars[i - 1], chars[i]) {
                dp[i] + dp[i - 1]
            } else {
                dp[i]
            };

            i += 1;
        }

        return dp[s.len()];
    }
}
// @lc code=end
