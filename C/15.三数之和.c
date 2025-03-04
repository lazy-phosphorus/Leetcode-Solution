/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

#include <limits.h>
#include <memory.h>
#include <stdlib.h>

// @lc code=start

static int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {
    int limit = 100, length = 0, i_cache = INT_MIN, left_cache = INT_MIN;
    int **result = (int **)calloc(limit, sizeof(int *));

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize && nums[i] <= 0; i++) {
        while (i < numsSize && nums[i] == i_cache) {
            i++;
        }
        if (i == numsSize) break;

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            if (nums[i] + nums[left] + nums[right] == 0) {
                if (length == limit) {
                    limit *= 2;
                    result = realloc(result, limit * sizeof(int *));
                }

                result[length] = (int *)calloc(3, sizeof(int));

                result[length][0] = nums[i];
                result[length][1] = nums[left];
                result[length][2] = nums[right];
                length++;

                left_cache = nums[left];
                i_cache = nums[i];
                while (left < right && left_cache == nums[left]) {
                    left++;
                }
            } else if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else
                left++;
        }
    }

    *returnSize = length;
    *returnColumnSizes = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return result;
}
// @lc code=end
