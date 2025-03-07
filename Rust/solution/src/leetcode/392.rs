/*
 * @lc app=leetcode.cn id=392 lang=rust
 *
 * [392] 判断子序列
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn is_subsequence(s: String, t: String) -> bool {
        if s.len() == 0 {
            return true;
        } else if t.len() < s.len() {
            return false;
        }

        let mut s_iter = s.chars().peekable();
        let mut t_iter = t.chars().peekable();
        while let Some(i) = s_iter.next() {
            while let Some(j) = t_iter.next() {
                if i == j {
                    if s_iter.peek().is_none() {
                        return true;
                    }
                    break;
                }
            }
            if t_iter.peek().is_none() {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
