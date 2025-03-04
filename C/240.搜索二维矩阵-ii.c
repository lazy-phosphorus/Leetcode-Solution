/*
 * @lc app=leetcode.cn id=240 lang=c
 *
 * [240] 搜索二维矩阵 II
 */

#include <stdbool.h>

// @lc code=start
static bool binary_search(int **matrix, int matrixSize, int *matrixColSize,
                          int line_number, int target) {
    int left = 0, right = matrixColSize[line_number] - 1,
        center = (left + right) / 2;
    while (left < right - 1) {
        if (matrix[line_number][center] == target)
            return true;
        else if (matrix[line_number][center] > target)
            right = center;
        else
            left = center;
        center = (left + right) / 2;
    }
    return target == matrix[line_number][left] ||
           target == matrix[line_number][right];
}

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize,
                  int target) {
    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] <= target &&
            target <= matrix[i][matrixColSize[i] - 1]) {
            if (binary_search(matrix, matrixSize, matrixColSize, i, target)) {
                return true;
            }
        }
    }
    return false;
}
// @lc code=end
