/*
 * @lc app=leetcode.cn id=113 lang=c
 *
 * [113] 路径总和 II
 */

#include <malloc.h>
#include <memory.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
static void dfs(struct TreeNode *root, int targetSum, int sum, int **path,
                int *path_size, int *path_capacity, int ***result,
                int **result_colum_size, int *result_size,
                int *result_capacity) {
    if ((*path_size) == (*path_capacity)) {
        (*path_capacity) *= 2;
        *path = (int *)realloc(*path, (*path_capacity) * sizeof(int));
    }
    (*path)[*path_size] = root->val;
    (*path_size)++;

    if (root->left == NULL && root->right == NULL &&
        root->val + sum == targetSum) {
        if ((*result_size) == (*result_capacity)) {
            (*result_capacity) *= 2;
            *result =
                (int **)realloc(*result, (*result_capacity) * sizeof(int *));
            *result_colum_size = (int *)realloc(
                *result_colum_size, (*result_capacity) * sizeof(int));
        }
        (*result)[*result_size] = (int *)calloc(*path_size, sizeof(int));
        memcpy((*result)[*result_size], *path, (*path_size) * sizeof(int));
        (*result_colum_size)[*result_size] = *path_size;
        (*path_size)--;
        (*result_size)++;
        return;
    }

    if (root->right != NULL)
        dfs(root->right, targetSum, sum + root->val, path, path_size,
            path_capacity, result, result_colum_size, result_size,
            result_capacity);
    if (root->left != NULL)
        dfs(root->left, targetSum, sum + root->val, path, path_size,
            path_capacity, result, result_colum_size, result_size,
            result_capacity);
    (*path_size)--;
}

int **pathSum(struct TreeNode *root, int targetSum, int *returnSize,
              int **returnColumnSizes) {
    if (root == NULL) {
        *returnColumnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    int result_capacity = 10, path_size = 0, path_capacity = 10,
        **result = (int **)calloc(result_capacity, sizeof(int *)),
        *path = (int *)calloc(path_capacity, sizeof(int));

    *returnSize = 0;
    *returnColumnSizes = (int *)calloc(result_capacity, sizeof(int));

    dfs(root, targetSum, 0, &path, &path_size, &path_capacity, &result,
        returnColumnSizes, returnSize, &result_capacity);

    free(path);
    return result;
}
// @lc code=end
