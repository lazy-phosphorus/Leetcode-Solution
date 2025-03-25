/*
 * @lc app=leetcode.cn id=2787 lang=rust
 *
 * [2787] 将一个数字表示成幂的和的方案数
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
fn pow(base: i32, index: i32) -> usize {
    if index == 1 {
        base as usize
    } else {
        pow(base, index - 1) * base as usize
    }
}

impl Solution {
    #[allow(dead_code)]
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        let mut dp: Vec<i32> = Vec::with_capacity(n as usize + 1);
        let mut i = 0;

        while i <= n {
            dp.push(0);
            i += 1;
        }

        i = 1;
        while pow(i, x) <= n as usize {
            let mut j = dp.len() - 1;
            while j > pow(i, x) {
                dp[j] += dp[j - pow(i, x)];
                dp[j] %= pow(10, 9) as i32 + 7;
                j -= 1;
            }
            dp[pow(i, x)] += 1;
            i += 1;
        }

        return dp[n as usize];
    }
}
// @lc code=end
