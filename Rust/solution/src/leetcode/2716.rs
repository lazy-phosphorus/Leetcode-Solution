/*
 * @lc app=leetcode.cn id=2716 lang=rust
 *
 * [2716] 最小化字符串长度
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn minimized_string_length(s: String) -> i32 {
        let mut result = 0;
        let mut cache = [false; 26];

        for c in s.chars() {
            if !cache[c as usize - 'a' as usize] {
                result += 1;
                cache[c as usize - 'a' as usize] = true;
            }
        }

        return result;
    }
}
// @lc code=end
