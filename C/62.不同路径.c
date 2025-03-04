/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 */

// @lc code=start

static int dyn(int m, int n, int x, int y) {
    if (x == m || y == n) return 1;

    return dyn(m, n, x + 1, y) + dyn(m, n, x, y + 1);
}

int uniquePaths(int m, int n) { return dyn(m, n, 1, 1); }
// @lc code=end
