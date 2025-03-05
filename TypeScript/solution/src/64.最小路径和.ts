/*
 * @lc app=leetcode.cn id=64 lang=typescript
 *
 * [64] 最小路径和
 */

// @lc code=start
function minPathSum(grid: number[][]): number {
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (j == 0 && i == 0) continue;
            else if (i == 0) grid[i][j] = grid[i][j - 1] + grid[i][j];
            else if (j == 0) grid[i][j] = grid[i - 1][j] + grid[i][j];
            else
                grid[i][j] =
                    Math.min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
    }
    return grid[grid.length - 1][grid[0].length - 1];
}
// @lc code=end
