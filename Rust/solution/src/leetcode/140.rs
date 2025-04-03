/*
 * @lc app=leetcode.cn id=140 lang=rust
 *
 * [140] 单词拆分 II
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn word_break(s: String, word_dict: Vec<String>) -> Vec<String> {
        let mut result: Vec<String> = Vec::new();
        let mut dp: Vec<Vec<Vec<&String>>> = Vec::with_capacity(s.len() + 1);
        dp.resize(dp.capacity(), Vec::new());

        let dp_len = dp.len();
        dp[dp_len - 1].push(Vec::new());
        let mut i = s.len();
        while let Some(index) = i.checked_sub(1) {
            if dp[index + 1].is_empty() {
                i = index;
                continue;
            }
            for word in &word_dict {
                let word_len = word.len();
                if word_len > index + 1 {
                    continue;
                }
                if &s[index - word_len + 1..index + 1] == word {
                    let mut prev = dp[index + 1].clone();
                    for j in &mut prev {
                        j.push(word);
                    }
                    dp[index - word_len + 1].append(&mut prev);
                }
            }
            i = index;
        }

        for elected in &dp[0] {
            let temp: Vec<String> = elected.iter().rev().map(|v| (**v).clone()).collect();
            result.push(temp.join(" "));
        }

        return result;
    }
}
// @lc code=end
