/*
 * @lc app=leetcode.cn id=337 lang=c
 *
 * [337] 打家劫舍 III
 */

#include <stddef.h>

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
typedef struct __Pair {
    int select_current;
    int ignore_current;
} Pair;

static inline int max(int a, int b) { return a > b ? a : b; }

static Pair dfs(struct TreeNode *root) {
    Pair ret = {0, 0}, left, right;
    if (root == NULL) return ret;

    left = dfs(root->left);
    right = dfs(root->right);

    ret.ignore_current = max(left.ignore_current, left.select_current) +
                         max(right.ignore_current, right.select_current);

    ret.select_current = left.ignore_current + right.ignore_current + root->val;

    return ret;
}

int rob(struct TreeNode *root) {
    Pair result = dfs(root);

    return max(result.ignore_current, result.select_current);
}
// @lc code=end
