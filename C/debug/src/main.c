#include <stdbool.h>
#include <stdio.h>

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

static inline int max(int a, int b) { return a > b ? a : b; }

static int dfs(struct TreeNode *root, bool is_stole) {
    int cache = 0;
    if (root == NULL) return 0;

    cache = dfs(root->left, false) + dfs(root->right, false);

    if (is_stole)
        return cache;
    else
        return max(dfs(root->left, true) + dfs(root->right, true) + root->val,
                   cache);
}

int rob(struct TreeNode *root) { return dfs(root, false); }

int main() {
    struct TreeNode a[5] = {{3}, {2}, {3}, {3}, {1}};

    a[0].left = &a[1];
    a[0].right = &a[2];
    a[1].left = NULL;
    a[1].right = &a[3];
    a[2].left = NULL;
    a[2].right = &a[4];
    a[3].left = NULL;
    a[3].right = NULL;
    a[4].left = NULL;
    a[4].right = NULL;

    printf("%d\n", rob(a));
    return 0;
}
