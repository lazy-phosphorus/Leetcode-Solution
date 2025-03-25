/*
 * @lc app=leetcode.cn id=1774 lang=rust
 *
 * [1774] 最接近目标价格的甜点成本
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::cmp::max;

impl Solution {
    #[allow(dead_code)]
    pub fn closest_cost(base_costs: Vec<i32>, topping_costs: Vec<i32>, target: i32) -> i32 {
        let mut max_base = target;
        for cost in &base_costs {
            max_base = max(max_base, *cost);
        }
        let mut dp: Vec<bool> = Vec::with_capacity(max_base as usize * 2);
        let mut i = 0;
        while i < dp.capacity() {
            dp.push(false);
            i += 1;
        }

        for cost in &base_costs {
            dp[*cost as usize] = true;
        }

        for cost in &topping_costs {
            i = target as usize;
            while i > 0 {
                if dp[i] {
                    if (i + *cost as usize) < dp.len() {
                        dp[i + *cost as usize] = true;
                    }
                    if (i + (*cost as usize * 2)) < dp.len() {
                        dp[i + (*cost as usize * 2)] = true;
                    }
                }
                i -= 1;
            }
        }

        let mut result = 0;
        i = 0;
        while target as usize >= i || target as usize + i < dp.len() {
            if target as usize >= i && dp[target as usize - i] {
                result = target - i as i32;
                break;
            }
            if target as usize + i < dp.len() && dp[target as usize + i] {
                result = target + i as i32;
                break;
            }
            i += 1;
        }

        return result;
    }
}
// @lc code=end
