/*
 * @lc app=leetcode.cn id=684 lang=c
 *
 * [684] 冗余连接
 */

#include <malloc.h>

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int uset_search(int *uset, int edgesSize, int target) {
    if (uset[target] != target)
        return uset_search(uset, edgesSize, uset[target]);

    return target;
}

int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize,
                             int *returnSize) {
    int *result = (int *)calloc(2, sizeof(int));
    int *uset = (int *)calloc(edgesSize, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        uset[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int cache_1 = uset_search(uset, edgesSize, edges[i][0] - 1);
        int cache_2 = uset_search(uset, edgesSize, edges[i][1] - 1);
        if (cache_1 != cache_2) {
            uset[cache_2] = cache_1;
        } else {
            result[0] = edges[i][0];
            result[1] = edges[i][1];
        }
    }

    free(uset);

    *returnSize = 2;
    return result;
}
// @lc code=end
