#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    private:
        unordered_map<TreeNode *, pair<int, int>> hashmap;

        int max(int a, int b) { return a > b ? a : b; }

        void dfs(TreeNode *root) {
            int left = 0, right = 0;
            pair<int, int> temp;

            if (root == nullptr) return;

            dfs(root->left);
            dfs(root->right);

            left = this->hashmap[root->left].first;
            right = this->hashmap[root->right].first;

            temp.first =
                max(left + right, this->hashmap[root->left].second +
                                      this->hashmap[root->right].second);
            temp.second = left + right + root->val;
            this->hashmap[root] = temp;
        }

    public:
        int rob(TreeNode *root) {
            this->hashmap[nullptr] = {0, 0};
            dfs(root);

            return max(this->hashmap[root].first, this->hashmap[root].second);
        }
};

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

    Solution s;

    cout << s.rob(a);
    return 0;
}
