/*
 * @lc app=leetcode.cn id=42 lang=rust
 *
 * [42] 接雨水
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::cmp::min;
impl Solution {
    #[allow(dead_code)]
    pub fn trap(height: Vec<i32>) -> i32 {
        if height.len() < 3 {
            return 0;
        }
        let mut left_height = height[0];
        let mut left_index = 0;
        let mut result = 0;
        let mut i = 1;
        while i < height.len() {
            if height[i] >= left_height {
                let mut j = left_index + 1;
                let horizon = min(left_height, height[i]);
                while j < i {
                    result += horizon - height[j];
                    j += 1;
                }
                left_height = height[i];
                left_index = i;
            }
            i += 1;
        }

        let mut overflowing = false;
        i = height.len() - 1;
        let mut right_height = height[i];
        let mut right_index = i;
        while !overflowing && i >= left_index {
            if height[i] >= right_height {
                let mut j = i + 1;
                let horizon = min(right_height, height[i]);
                while j < right_index {
                    result += horizon - height[j];
                    j += 1;
                }
                right_height = height[i];
                right_index = i;
            }
            (i, overflowing) = i.overflowing_sub(1);
        }
        return result;
    }
}
// @lc code=end
