/*
 * @lc app=leetcode.cn id=151 lang=rust
 *
 * [151] 反转字符串中的单词
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn reverse_words(s: String) -> String {
        let mut stack: Vec<char> = Vec::new();
        let mut result = String::new();
        let iter = s.char_indices().rev();

        for (_, ch) in iter {
            if ch == ' ' && stack.len() > 0 {
                while let Some(v) = stack.pop() {
                    result.push(v);
                }
                result.push(' ');
            } else if ch != ' ' {
                stack.push(ch);
            }
        }
        if stack.len() > 0 {
            while let Some(v) = stack.pop() {
                result.push(v);
            }
        } else {
            result.pop();
        }

        return result;
    }
}
// @lc code=end
