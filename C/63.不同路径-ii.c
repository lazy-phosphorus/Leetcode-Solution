/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 */

// @lc code=start

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize,
                             int *obstacleGridColSize) {
    if (obstacleGrid[0][0] == 1 ||
        obstacleGrid[obstacleGridSize - 1]
                    [obstacleGridColSize[obstacleGridSize - 1] - 1] == 1)
        return 0;

    for (int i = 0; i < obstacleGridSize; i++) {
        for (int j = 0; j < obstacleGridColSize[i]; j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0) {
                obstacleGrid[i][j] = 1;
                continue;
            }

            if (i != 0) obstacleGrid[i][j] += obstacleGrid[i - 1][j];
            if (j != 0) obstacleGrid[i][j] += obstacleGrid[i][j - 1];
        }
    }
    return obstacleGrid[obstacleGridSize - 1]
                       [obstacleGridColSize[obstacleGridSize - 1] - 1];
}
// @lc code=end
