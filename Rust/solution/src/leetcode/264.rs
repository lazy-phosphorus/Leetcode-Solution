/*
 * @lc app=leetcode.cn id=264 lang=rust
 *
 * [264] 丑数 II
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn nth_ugly_number(n: i32) -> i32 {
        let mut cache: Vec<i32> = Vec::with_capacity(n as usize);

        cache.push(1);
        let mut i2 = 0;
        let mut i3 = 0;
        let mut i5 = 0;
        while cache.len() < cache.capacity() {
            let temp2 = cache[i2] * 2;
            let temp3 = cache[i3] * 3;
            let temp5 = cache[i5] * 5;
            if temp2 <= temp3 && temp2 <= temp5 {
                if cache[cache.len() - 1] < temp2 {
                    cache.push(temp2);
                }
                i2 += 1;
            } else if temp3 <= temp2 && temp3 <= temp5 {
                if cache[cache.len() - 1] < temp3 {
                    cache.push(temp3);
                }
                i3 += 1;
            } else if temp5 <= temp2 && temp5 <= temp3 {
                if cache[cache.len() - 1] < temp5 {
                    cache.push(temp5);
                }
                i5 += 1;
            }
        }

        return cache[n as usize - 1];
    }
}
// @lc code=end
