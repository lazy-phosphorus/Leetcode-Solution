/*
 * @lc app=leetcode.cn id=2874 lang=rust
 *
 * [2874] 有序三元组中的最大值 II
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::{cmp::max, i32};

impl Solution {
    #[allow(dead_code)]
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut left: Vec<i32> = Vec::with_capacity(nums.len());
        let mut right: Vec<i32> = Vec::with_capacity(nums.len());

        left.resize(left.capacity(), 0);
        right.resize(right.capacity(), 0);

        let mut max_num = i32::MIN;
        let mut i = 1;
        while i < nums.len() - 1 {
            max_num = max(max_num, nums[i - 1]);
            left[i] = max_num;
            i += 1;
        }

        let mut max_num = i32::MIN;
        let mut i = nums.len() - 2;
        while i >= 1 {
            max_num = max(max_num, nums[i + 1]);
            right[i] = max_num;
            i -= 1;
        }

        let mut result = 0;
        let mut i = 1;
        while i < nums.len() - 1 {
            result = max(result, (left[i] - nums[i]) as i64 * right[i] as i64);
            i += 1;
        }

        return result;
    }
}
// @lc code=end
