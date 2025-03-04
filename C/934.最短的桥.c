/*
 * @lc app=leetcode.cn id=934 lang=c
 *
 * [934] 最短的桥
 */

#include <limits.h>
#include <malloc.h>
#include <stdbool.h>

// @lc code=start
typedef struct __Point {
    int x;
    int y;
    int counter;
} Point;

static void dfs(int **grid, int gridSize, int *gridColSize, int x, int y,
                Point *queue, int *size) {
    if (x < 0 || y < 0 || x >= gridSize || y >= gridColSize[x] ||
        grid[x][y] != 1)
        return;

    grid[x][y] = 2;
    Point temp = {x, y, 0};
    queue[*size] = temp;
    (*size)++;
    if (x > 0) dfs(grid, gridSize, gridColSize, x - 1, y, queue, size);
    if (x < gridSize - 1)
        dfs(grid, gridSize, gridColSize, x + 1, y, queue, size);
    if (y > 0) dfs(grid, gridSize, gridColSize, x, y - 1, queue, size);
    if (y < gridColSize[x] - 1)
        dfs(grid, gridSize, gridColSize, x, y + 1, queue, size);
}

int shortestBridge(int **grid, int gridSize, int *gridColSize) {
    bool colored_flag = false;
    int head = 0, tail = 0, size = 0, result = INT_MAX;
    Point *queue = (Point *)calloc(4096, sizeof(Point));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, gridSize, gridColSize, i, j, queue, &size);
                colored_flag = true;
                break;
            }
        }
        if (colored_flag) break;
    }

    tail = size;
    while (size > 0) {
        Point p = queue[head];

        if (p.x > 0) {
            if (grid[p.x - 1][p.y] == 1)
                return p.counter;
            else if (grid[p.x - 1][p.y] == 0) {
                grid[p.x - 1][p.y] = -1;
                Point temp = {p.x - 1, p.y, p.counter + 1};
                queue[tail] = temp;
                tail = (tail + 1) % 4096;
                size++;
            }
        }
        if (p.x < gridSize - 1) {
            if (grid[p.x + 1][p.y] == 1)
                return p.counter;
            else if (grid[p.x + 1][p.y] == 0) {
                grid[p.x + 1][p.y] = -1;
                Point temp = {p.x + 1, p.y, p.counter + 1};
                queue[tail] = temp;
                tail = (tail + 1) % 4096;
                size++;
            }
        }
        if (p.y > 0) {
            if (grid[p.x][p.y - 1] == 1)
                return p.counter;
            else if (grid[p.x][p.y - 1] == 0) {
                grid[p.x][p.y - 1] = -1;
                Point temp = {p.x, p.y - 1, p.counter + 1};
                queue[tail] = temp;
                tail = (tail + 1) % 4096;
                size++;
            }
        }
        if (p.y < gridColSize[p.x] - 1) {
            if (grid[p.x][p.y + 1] == 1)
                return p.counter;
            else if (grid[p.x][p.y + 1] == 0) {
                grid[p.x][p.y + 1] = -1;
                Point temp = {p.x, p.y + 1, p.counter + 1};
                queue[tail] = temp;
                tail = (tail + 1) % 4096;
                size++;
            }
        }

        size--;
        head = (head + 1) % 4096;
    }

    free(queue);

    return 0;
}
// @lc code=end
