/*
 * @lc app=leetcode.cn id=547 lang=c
 *
 * [547] 省份数量
 */

// @lc code=start
static void dfs(int **isConnected, int isConnectedSize, int *isConnectedColSize,
                int x, int y) {
    if (x >= isConnectedSize || x < 0 || y >= isConnectedColSize[x] || y < 0 ||
        isConnected[x][y] != 1)
        return;

    isConnected[x][y] = 2;

    for (int i = 0; i < isConnectedColSize[y]; i++) {
        if (isConnected[y][i] == 1)
            dfs(isConnected, isConnectedSize, isConnectedColSize, y, i);
    }
}

int findCircleNum(int **isConnected, int isConnectedSize,
                  int *isConnectedColSize) {
    int result = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        for (int j = 0; j < isConnectedColSize[i]; j++) {
            if (isConnected[i][j] == 1) {
                result++;
                dfs(isConnected, isConnectedSize, isConnectedColSize, i, j);
            }
        }
    }
    return result;
}
// @lc code=end
