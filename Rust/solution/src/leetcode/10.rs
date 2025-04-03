/*
 * @lc app=leetcode.cn id=10 lang=rust
 *
 * [10] 正则表达式匹配
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start

/* 我看不懂，但我大为震撼 */
impl Solution {
    #[allow(dead_code)]
    pub fn is_match(s: String, p: String) -> bool {
        let pchars: Vec<char> = p.chars().collect();
        let schars: Vec<char> = s.chars().collect();

        let mut dp: Vec<Vec<bool>> = Vec::with_capacity(schars.len() + 1);
        let mut line: Vec<bool> = Vec::with_capacity(pchars.len() + 1);
        line.resize(line.capacity(), false);
        dp.resize(dp.capacity(), line);
        dp[0][0] = true;

        let mut i = 1;
        while i < pchars.len() {
            if pchars[i] == '*' {
                dp[0][i + 1] |= dp[0][i - 1];
            }
            i += 1;
        }

        let mut i = 0;
        while i < schars.len() {
            let mut j = 0;
            while j < pchars.len() {
                if pchars[j] == '*' {
                    dp[i + 1][j + 1] |= dp[i + 1][j - 1];
                    if pchars[j - 1] == '.' || pchars[j - 1] == schars[i] {
                        dp[i + 1][j + 1] |= dp[i][j + 1];
                    }
                } else if pchars[j] == '.' || pchars[j] == schars[i] {
                    dp[i + 1][j + 1] |= dp[i][j];
                }
                j += 1;
            }
            i += 1;
        }

        return dp[schars.len()][pchars.len()];
    }
}
// @lc code=end
