/*
 * @lc app=leetcode.cn id=120 lang=rust
 *
 * [120] 三角形最小路径和
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut cache: Vec<Vec<i32>> = Vec::new();
        let mut i = 1;
        let mut result = i32::MAX;
        cache.push(triangle[0].clone());
        while i < triangle.len() {
            let mut temp: Vec<i32> = Vec::new();
            let mut j = 0;
            while j < triangle[i].len() {
                let value = match j {
                    0 => cache[i - 1][j],
                    v if v == triangle[i].len() - 1 => cache[i - 1][v - 1],
                    v => std::cmp::min(cache[i - 1][v - 1], cache[i - 1][v]),
                };
                temp.push(value + triangle[i][j]);
                j += 1;
            }
            cache.push(temp);
            i += 1;
        }

        for i in &cache[cache.len() - 1] {
            result = std::cmp::min(result, *i);
        }
        return result;
    }
}
// @lc code=end
