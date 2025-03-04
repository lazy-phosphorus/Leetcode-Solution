/*
 * @lc app=leetcode.cn id=289 lang=c
 *
 * [289] 生命游戏
 */

// @lc code=start
#define DEAD_CELL 0
#define ALIVE_CELL 1
#define WILL_LIVE_CELL 2
#define WILL_DIE_CELL 3
void gameOfLife(int **board, int boardSize, int *boardColSize) {
    int alive_cell_counter = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            alive_cell_counter = 0;
            if (i > 0 && j > 0) alive_cell_counter += board[i - 1][j - 1] % 2;
            if (i > 0) alive_cell_counter += board[i - 1][j] % 2;
            if (j > 0) alive_cell_counter += board[i][j - 1] % 2;

            if (i < boardSize - 1 && j < boardColSize[i] - 1)
                alive_cell_counter += board[i + 1][j + 1] % 2;
            if (i < boardSize - 1) alive_cell_counter += board[i + 1][j] % 2;
            if (j < boardColSize[i] - 1)
                alive_cell_counter += board[i][j + 1] % 2;

            if (i > 0 && j < boardColSize[i] - 1)
                alive_cell_counter += board[i - 1][j + 1] % 2;
            if (i < boardSize - 1 && j > 0)
                alive_cell_counter += board[i + 1][j - 1] % 2;

            if (board[i][j] == DEAD_CELL && alive_cell_counter == 3)
                board[i][j] = WILL_LIVE_CELL;
            else if (board[i][j] == ALIVE_CELL &&
                     (alive_cell_counter < 2 || alive_cell_counter > 3))
                board[i][j] = WILL_DIE_CELL;
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == WILL_LIVE_CELL)
                board[i][j] = ALIVE_CELL;
            else if (board[i][j] == WILL_DIE_CELL)
                board[i][j] = DEAD_CELL;
        }
    }
}
// @lc code=end
