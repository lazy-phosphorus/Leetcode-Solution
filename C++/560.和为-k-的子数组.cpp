/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    public:
        int subarraySum(vector<int> &nums, int k) {
            int sum = 0, result = 0;
            unordered_map<int, int> hashmap;

            hashmap[0] = 1;

            vector<int>::iterator p = nums.begin();
            while (p != nums.end()) {
                sum += *p;

                if (hashmap.find(sum - k) != hashmap.end())
                    result += hashmap[sum - k];

                if (hashmap.find(sum) != hashmap.end())
                    hashmap[sum]++;
                else
                    hashmap[sum] = 1;

                p++;
            }

            return result;
        }
};
// @lc code=end
