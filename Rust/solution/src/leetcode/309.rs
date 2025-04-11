/*
 * @lc app=leetcode.cn id=309 lang=rust
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::cmp::max;

impl Solution {
    #[allow(dead_code)]
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut hold_profit = -prices[0];
        let mut freezed_profit = 0;
        let mut sold_profit = 0;

        let mut i = 0;
        while i < prices.len() {
            let buy = max(hold_profit, sold_profit - prices[i]);
            let sold = hold_profit + prices[i];
            sold_profit = max(sold_profit, freezed_profit);

            hold_profit = buy;
            freezed_profit = sold;

            i += 1;
        }

        return max(sold_profit, freezed_profit);
    }
}
// @lc code=end
