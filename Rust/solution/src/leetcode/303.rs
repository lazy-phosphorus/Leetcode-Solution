/*
 * @lc app=leetcode.cn id=303 lang=rust
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#[allow(dead_code)]
struct NumArray {
    dp: Vec<Vec<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {
    #[allow(dead_code)]
    fn new(nums: Vec<i32>) -> Self {
        let mut dp: Vec<Vec<i32>> = Vec::with_capacity(nums.len());
        let mut line: Vec<i32> = Vec::with_capacity(nums.len());
        line.resize(line.capacity(), 0);
        dp.resize(dp.capacity(), line);

        let mut i = 0;
        while i < nums.len() {
            dp[i][i] = nums[i];
            let mut j = i + 1;
            while j < nums.len() {
                dp[i][j] = dp[i][j - 1] + nums[j];
                j += 1;
            }
            i += 1;
        }

        return NumArray { dp };
    }

    #[allow(dead_code)]
    fn sum_range(&self, left: i32, right: i32) -> i32 {
        return self.dp[left as usize][right as usize];
    }
}

// /**
//  * Your NumArray object will be instantiated and called as such:
//  * let obj = NumArray::new(nums);
//  * let ret_1: i32 = obj.sum_range(left, right);
//  */
// @lc code=end
