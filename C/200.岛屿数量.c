/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

#include <malloc.h>

// @lc code=start

typedef struct __Point {
    int x;
    int y;
} Point;

typedef struct __Stack {
    Point *stack;
    int size;
    int capacity;
} Stack;

static void stack_push(Stack *this, Point p) {
    if (this->size == this->capacity) {
        this->capacity *= 2;
        this->stack =
            (Point *)realloc(this->stack, sizeof(Point) * this->capacity);
    }
    this->stack[this->size] = p;
    this->size++;
}

static void stack_pop(Stack *this) {
    if (this->size == 0) return;

    this->size--;
}

static Point stack_top(Stack *this) { return this->stack[this->size - 1]; }

static void dfs(char **grid, int gridSize, int *gridColSize, Stack *stack) {
    while (stack->size != 0) {
        Point current = stack_top(stack);
        stack_pop(stack);
        grid[current.x][current.y] = '2';
        if (current.x > 0 && grid[current.x - 1][current.y] == '1') {
            Point temp = {current.x - 1, current.y};
            stack_push(stack, temp);
        }
        if (current.y > 0 && grid[current.x][current.y - 1] == '1') {
            Point temp = {current.x, current.y - 1};
            stack_push(stack, temp);
        }
        if (current.x < gridSize - 1 && grid[current.x + 1][current.y] == '1') {
            Point temp = {current.x + 1, current.y};
            stack_push(stack, temp);
        }
        if (current.y < gridColSize[current.x] - 1 &&
            grid[current.x][current.y + 1] == '1') {
            Point temp = {current.x, current.y + 1};
            stack_push(stack, temp);
        }
    }
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
    int counter = 0;
    Stack stack;
    stack.capacity = 100;
    stack.size = 0;
    stack.stack = (Point *)calloc(stack.capacity, sizeof(Point));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                counter++;
                Point temp = {i, j};
                stack_push(&stack, temp);
                dfs(grid, gridSize, gridColSize, &stack);
            }
        }
    }

    free(stack.stack);

    return counter;
}
// @lc code=end
