/*
 * @lc app=leetcode.cn id=494 lang=c
 *
 * [494] 目标和
 */

#include <malloc.h>

// @lc code=start
int findTargetSumWays(int *nums, int numsSize, int target) {
    int sum = 0, result = 0, *cache = NULL;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    if (target < 0) target = -target;
    if (sum < target || (sum - target) % 2 == 1) return 0;

    cache = (int *)calloc((sum - target) / 2 + 1, sizeof(int));
    cache[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = (sum - target) / 2; j >= nums[i]; j--) {
            cache[j] += cache[j - nums[i]];
        }
    }
    result = cache[(sum - target) / 2];

    free(cache);

    return result;
}
// @lc code=end
