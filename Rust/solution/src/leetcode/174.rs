/*
 * @lc app=leetcode.cn id=174 lang=rust
 *
 * [174] 地下城游戏
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::{
    cmp::{max, min},
    i32,
};

impl Solution {
    #[allow(dead_code)]
    pub fn calculate_minimum_hp(dungeon: Vec<Vec<i32>>) -> i32 {
        // [0] 代表路径上的最大损耗，[1] 代表当前损耗，均为负值
        let mut dp: Vec<i32> = Vec::with_capacity(dungeon[0].len());
        dp.resize(dp.capacity(), 0);

        let mut index_i = dungeon.len();
        while let Some(i) = index_i.checked_sub(1) {
            let mut index_j = dungeon[i].len();
            while let Some(j) = index_j.checked_sub(1) {
                let temp = if j != dungeon[i].len() - 1 && i != dungeon.len() - 1 {
                    min(dp[j + 1], dp[j])
                } else if j != dungeon[i].len() - 1 {
                    dp[j + 1]
                } else {
                    dp[j]
                } - dungeon[i][j];
                dp[j] = max(temp, 0);
                index_j = j;
            }

            index_i = i;
        }

        return dp[0] + 1;
    }
}
// @lc code=end
