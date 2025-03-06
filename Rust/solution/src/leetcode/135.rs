/*
 * @lc app=leetcode.cn id=135 lang=rust
 *
 * [135] 分发糖果
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start

// “相邻两个孩子评分更高的孩子会获得更多的糖果”
// 分数相等的俩孩子可以差别对待
// 好好好这么玩儿
impl Solution {
    #[allow(dead_code)]
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let mut result = ratings.len() as i32;
        let mut increase_length = 0;
        let mut decrease_length = 0;
        let mut i = 1;
        while i < ratings.len() {
            if ratings[i] > ratings[i - 1] {
                if decrease_length != 0 {
                    increase_length = 0;
                }
                decrease_length = 0;
                increase_length += 1;
                result += increase_length;
            } else if ratings[i] < ratings[i - 1] {
                decrease_length += 1;
                result += if decrease_length <= increase_length {
                    decrease_length - 1
                } else {
                    decrease_length
                };
            } else {
                increase_length = 0;
                decrease_length = 0;
            }

            i += 1;
        }

        return result;
    }
}
// @lc code=end
