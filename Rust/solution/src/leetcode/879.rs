/*
 * @lc app=leetcode.cn id=879 lang=rust
 *
 * [879] 盈利计划
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::cmp::max;

impl Solution {
    #[allow(dead_code)]
    pub fn profitable_schemes(n: i32, min_profit: i32, group: Vec<i32>, profit: Vec<i32>) -> i32 {
        let mut dp: Vec<Vec<i32>> = Vec::with_capacity(n as usize + 1);

        let mut i = 0;
        while i < dp.capacity() {
            dp.push(Vec::with_capacity(min_profit as usize + 1));
            let mut j = 0;
            while j < dp[i].capacity() {
                dp[i].push(if j == 0 { 1 } else { 0 });
                j += 1;
            }
            i += 1;
        }

        let mut i = 0;
        while i < profit.len() {
            let mut j = n;
            while j >= group[i] {
                let mut k = min_profit;
                while k >= 0 {
                    dp[j as usize][k as usize] +=
                        dp[(j - group[i]) as usize][max(k - profit[i], 0) as usize];
                    if dp[j as usize][k as usize] > 1000000007 {
                        dp[j as usize][k as usize] -= 1000000007;
                    }
                    k -= 1;
                }
                j -= 1;
            }
            i += 1;
        }

        return dp[n as usize][min_profit as usize];
    }
}
// @lc code=end
