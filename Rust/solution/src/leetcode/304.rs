/*
 * @lc app=leetcode.cn id=304 lang=rust
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#[allow(dead_code)]
struct NumMatrix {
    sum: Vec<Vec<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumMatrix {
    #[allow(dead_code)]
    fn new(matrix: Vec<Vec<i32>>) -> Self {
        let mut sum: Vec<Vec<i32>> = Vec::with_capacity(matrix.len());
        let mut line: Vec<i32> = Vec::with_capacity(matrix[0].len());
        line.resize(line.capacity(), 0);
        sum.resize(sum.capacity(), line);

        let mut i = 0;
        while i < matrix.len() {
            let mut j = 0;
            while j < matrix[i].len() {
                sum[i][j] = if i > 0 && j > 0 {
                    sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]
                } else if i > 0 {
                    sum[i - 1][j]
                } else if j > 0 {
                    sum[i][j - 1]
                } else {
                    0
                } + matrix[i][j];
                j += 1;
            }
            i += 1;
        }

        return NumMatrix { sum };
    }

    #[allow(dead_code)]
    fn sum_region(&self, row1: i32, col1: i32, row2: i32, col2: i32) -> i32 {
        return self.sum[row2 as usize][col2 as usize]
            - if row1 > 0 {
                self.sum[row1 as usize - 1][col2 as usize]
            } else {
                0
            }
            - if col1 > 0 {
                self.sum[row2 as usize][col1 as usize - 1]
            } else {
                0
            }
            + if row1 > 0 && col1 > 0 {
                self.sum[row1 as usize - 1][col1 as usize - 1]
            } else {
                0
            };
    }
}

// /**
//  * Your NumMatrix object will be instantiated and called as such:
//  * let obj = NumMatrix::new(matrix);
//  * let ret_1: i32 = obj.sum_region(row1, col1, row2, col2);
//  */
// @lc code=end
