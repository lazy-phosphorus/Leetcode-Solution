/*
 * @lc app=leetcode.cn id=300 lang=rust
 *
 * [300] 最长递增子序列
 */

struct Solution {}

// @lc code=start
use std::cmp::max;

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut cache: Vec<i32> = Vec::new();
        cache.push(1);
        let mut i = 1;
        while i < nums.len() {
            let mut j = Some(i - 1);
            let mut partial_max = 0;
            while let Some(k) = j {
                if nums[i] > nums[k] {
                    partial_max = max(cache[k], partial_max);
                }
                j = k.checked_sub(1);
            }

            cache.push(partial_max + 1);
            i += 1;
        }

        let mut result = 0;
        for count in cache {
            result = max(result, count);
        }

        return result;
    }
}
// @lc code=end
