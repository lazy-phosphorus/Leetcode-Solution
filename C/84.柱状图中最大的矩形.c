/*
 * @lc app=leetcode.cn id=84 lang=c
 *
 * [84] 柱状图中最大的矩形
 */

#include <malloc.h>

// @lc code=start

struct Pair {
    int value;
    int index;
};

static inline int max(int a, int b) { return a > b ? a : b; }

int largestRectangleArea(int *heights, int heightsSize) {
    struct Pair *stack =
        (struct Pair *)calloc(heightsSize, sizeof(struct Pair));
    int *left = (int *)calloc(heightsSize, sizeof(int)),
        *right = (int *)calloc(heightsSize, sizeof(int)), stack_size = 0,
        result = 0;

    for (int i = 0; i < heightsSize; i++) {
        int j = stack_size - 1;
        while (j >= 0 && stack[j].value >= heights[i]) {
            j--;
        }
        if (j == -1)
            left[i] = -1;
        else
            left[i] = stack[j].index;
        struct Pair temp = {heights[i], i};
        stack[j + 1] = temp;
        stack_size = j + 2;
    }

    stack_size = 0;
    for (int i = heightsSize - 1; i >= 0; i--) {
        int j = stack_size - 1;
        while (j >= 0 && stack[j].value >= heights[i]) {
            j--;
        }
        if (j == -1)
            right[i] = heightsSize;
        else
            right[i] = stack[j].index;
        struct Pair temp = {heights[i], i};
        stack[j + 1] = temp;
        stack_size = j + 2;
    }

    for (int i = 0; i < heightsSize; i++) {
        result = max(result, heights[i] * (right[i] - left[i] - 1));
    }

    free(left);
    free(right);
    free(stack);
    return result;
}
// @lc code=end
