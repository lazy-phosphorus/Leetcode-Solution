/*
 * @lc app=leetcode.cn id=30 lang=rust
 *
 * [30] 串联所有单词的子串
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::collections::HashMap;

fn insert<'a, 'b: 'a>(map: &'a mut HashMap<&'b str, i32>, word: &'b str, diff: &mut i32) {
    if let Some(v) = map.get(&word[..]) {
        *diff += if *v < 0 { -1 } else { 1 };
        map.insert(word, *v + 1);
    } else {
        *diff += 1;
        map.insert(word, 1);
    }
}

fn remove<'a, 'b: 'a>(map: &'a mut HashMap<&'b str, i32>, word: &'b str, diff: &mut i32) {
    if let Some(v) = map.get(&word[..]) {
        *diff += if *v > 0 { -1 } else { 1 };
        map.insert(word, *v - 1);
    } else {
        *diff += 1;
        map.insert(word, -1);
    }
}

impl Solution {
    #[allow(dead_code)]
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let mut map: HashMap<&str, i32> = HashMap::new();
        let mut result: Vec<i32> = Vec::new();
        let mut diff = 0;
        let step = words[0].len();

        let mut i = 0;
        while i < step {
            for word in &words {
                insert(&mut map, word, &mut diff);
            }
            let mut j = 0;
            while j < words.len() && i + (j + 1) * step <= s.len() {
                let word = &s[i + j * step..i + (j + 1) * step];
                remove(&mut map, word, &mut diff);
                j += 1;
            }

            if diff == 0 {
                result.push(i as i32);
            }

            j = i;
            while j + words.len() * step + step <= s.len() {
                let prev_word = &s[j..j + step];
                let new_word = &s[j + words.len() * step..j + words.len() * step + step];
                insert(&mut map, prev_word, &mut diff);
                remove(&mut map, new_word, &mut diff);
                if diff == 0 {
                    result.push((j + step) as i32);
                }
                j += step;
            }
            map.clear();
            diff = 0;
            i += 1;
        }

        return result;
    }
}
// @lc code=end
