/*
 * @lc app=leetcode.cn id=68 lang=rust
 *
 * [68] 文本左右对齐
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
impl Solution {
    #[allow(dead_code)]
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut result: Vec<String> = Vec::new();
        let mut queue: Vec<String> = Vec::new();
        let mut current_width = 0;
        for word in words {
            if word.len() + current_width > max_width as usize {
                let mut line = String::new();
                let left = if queue.len() == 1 {
                    0
                } else {
                    (max_width as usize + queue.len() - current_width) % (queue.len() - 1)
                };
                let gaps = if queue.len() == 1 {
                    max_width as usize + 1 - current_width
                } else {
                    (max_width as usize + queue.len() - current_width) / (queue.len() - 1)
                };
                let mut whitespaces = String::new();
                let mut i = 0;
                while i < gaps {
                    whitespaces.push(' ');
                    i += 1;
                }
                i = 0;
                while i < queue.len() {
                    line += &queue[i];
                    i += 1;
                    if i != queue.len() || queue.len() == 1 {
                        line += &whitespaces;
                        if i <= left && left != 0 {
                            line.push(' ');
                        }
                    }
                }
                current_width = 0;
                result.push(line);
                queue.clear();
            }
            current_width += word.len() + 1;
            queue.push(word);
        }

        let mut line = queue.join(" ");
        while line.len() < max_width as usize {
            line.push(' ');
        }
        result.push(line);

        return result;
    }
}
// @lc code=end
