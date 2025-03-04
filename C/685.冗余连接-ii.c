/*
 * @lc app=leetcode.cn id=685 lang=c
 *
 * [685] 冗余连接 II
 */

#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 树的边数为 n，则结点数为 n+1
// 怎么给这等式忘了（恼
/**
 * 并查集，情况分三种：
 * 1. 有环无冲突（叶子结点指向根节点）
 * 2. 无环冲突（指向兄弟分支）
 * 3. 有环冲突（后代结点指向祖先结点）
 * 第二种情况又可以细分，即仅冲突
 */

static int uset_search(int *uset, int value) {
    if (uset[value] == value) return value;

    return uset_search(uset, uset[value]);
}

int *findRedundantDirectedConnection(int **edges, int edgesSize,
                                     int *edgesColSize, int *returnSize) {
    int conflict = -1, cycle = -1, *result = (int *)calloc(2, sizeof(int)),
        *uset = (int *)calloc(edgesSize, sizeof(int)),
        *parent = (int *)calloc(edgesSize, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        uset[i] = i;
        parent[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0] - 1, to = edges[i][1] - 1,
            from_parent = uset_search(uset, from),
            to_parent = uset_search(uset, to);
        if (to_parent != to) {
            conflict = i;
            result[0] = from + 1;
            result[1] = to + 1;
        } else if (from_parent == to_parent) {
            cycle = i;
            parent[to] = from;
            result[0] = from + 1;
            result[1] = to + 1;
        } else {
            parent[to] = from;
            uset[to] = from;
        }
    }

    if (conflict != -1 && cycle != -1) {
        result[0] = parent[edges[conflict][1] - 1] + 1;
        result[1] = edges[conflict][1];
    }

    free(uset);
    free(parent);

    *returnSize = 2;
    return result;
}
// @lc code=end
