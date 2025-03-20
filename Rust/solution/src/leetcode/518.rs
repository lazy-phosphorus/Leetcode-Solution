/*
 * @lc app=leetcode.cn id=518 lang=rust
 *
 * [518] 零钱兑换 II
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let mut dp: Vec<i32> = Vec::with_capacity(amount as usize + 1);
        while dp.len() <= amount as usize {
            dp.push(0);
        }
        dp[0] = 1;

        for coin in &coins {
            let mut i = *coin as usize;
            while i < dp.len() {
                let temp = i - *coin as usize;
                dp[i] += dp[temp];
                i += 1;
            }
        }

        return dp[amount as usize];
    }
}
// @lc code=end
