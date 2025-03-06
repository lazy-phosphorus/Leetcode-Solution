/*
 * @lc app=leetcode.cn id=134 lang=rust
 *
 * [134] 加油站
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut i = 0;
        while i < gas.len() {
            if gas[i] >= cost[i] {
                let mut gas_left = gas[i] - cost[i];
                let mut j = (i + 1) % gas.len();
                while j != i && gas_left >= 0 {
                    gas_left += gas[j] - cost[j];
                    j = (j + 1) % gas.len();
                }
                if gas_left >= 0 {
                    return i as i32;
                } else if j <= i {
                    return -1;
                } else {
                    i = j;
                    continue;
                }
            }
            i += 1;
        }
        return -1;
    }
}
// @lc code=end
