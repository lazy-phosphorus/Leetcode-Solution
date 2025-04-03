/*
 * @lc app=leetcode.cn id=152 lang=rust
 *
 * [152] 乘积最大子数组
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::cmp::max;
use std::i32;

impl Solution {
    #[allow(dead_code)]
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut result = i32::MIN;
        let mut left = 0;
        let mut dp = 1;

        let mut i = 0;
        while i < nums.len() {
            if nums[i] == 0 {
                // 计算“左乘”最大值
                result = max(result, 0);
                if i != 0 {
                    let mut j = i - 1;
                    dp = 1;
                    while j > left {
                        dp *= nums[j];
                        result = max(dp, result);
                        j -= 1;
                    }
                    if left == 0 && nums[left] != 0 {
                        dp *= nums[j];
                        result = max(dp, result);
                    }
                    dp = 1;
                    left = i;
                }
            } else {
                // 计算“右乘”最大值
                dp *= nums[i];
                result = max(dp, result);
            }
            i += 1;
        }

        // 计算最后一次右乘
        let mut j = nums.len() - 1;
        dp = 1;
        while j > left {
            dp *= nums[j];
            result = max(dp, result);
            j -= 1;
        }
        if left == 0 && nums[left] != 0 {
            dp *= nums[j];
            result = max(dp, result);
        }

        return result;
    }
}
// @lc code=end
