/*
 * @lc app=leetcode.cn id=238 lang=c
 *
 * [238] 除自身以外数组的乘积
 */

#include <malloc.h>

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    int *result = (int *)calloc(numsSize, sizeof(int));
    int *right = (int *)calloc(numsSize, sizeof(int));

    result[0] = 1;
    right[numsSize - 1] = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        result[i + 1] = result[i] * nums[i];
        right[numsSize - i - 2] =
            right[numsSize - i - 1] * nums[numsSize - i - 1];
    }

    for (int i = 0; i < numsSize; i++) {
        result[i] *= right[i];
    }

    free(right);

    *returnSize = numsSize;
    return result;
}
// @lc code=end
