/*
 * @lc app=leetcode.cn id=416 lang=c
 *
 * [416] 分割等和子集
 */

#include <malloc.h>
#include <stdbool.h>

// @lc code=start
bool canPartition(int *nums, int numsSize) {
    int sum = 0;
    bool *cache = NULL, result = false;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    if (sum % 2 == 1) {
        return false;
    }
    cache = (bool *)calloc(sum / 2 + 1, sizeof(bool));
    cache[0] = true;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > sum / 2) {
            free(cache);
            return false;
        }
        for (int j = sum / 2; j >= nums[i]; j--) {
            cache[j] = cache[j] || cache[j - nums[i]];
        }
    }

    result = cache[sum / 2];
    free(cache);

    return result;
}
// @lc code=end
