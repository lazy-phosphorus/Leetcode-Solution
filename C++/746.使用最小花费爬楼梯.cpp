/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    private:
        vector<int> mincost;

        int impl(vector<int> &cost, int height) {
            if (height >= cost.size()) {
                return 0;
            }
            if (this->mincost[height] == INT_MAX) {
                this->mincost[height] = min(this->impl(cost, height + 1),
                                            this->impl(cost, height + 2)) +
                                        cost[height];
            }
            return this->mincost[height];
        }

    public:
        int minCostClimbingStairs(vector<int> &cost) {
            for (size_t i = 0; i < cost.size(); i++) {
                mincost.push_back(INT_MAX);
            }
            return min(impl(cost, 0), impl(cost, 1));
        }
};
// @lc code=end
