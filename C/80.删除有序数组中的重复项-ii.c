/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除有序数组中的重复项 II
 */

#include <limits.h>

// @lc code=start
int removeDuplicates(int *nums, int numsSize) {
    int length = 2;

    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[length - 2]) {
            nums[length] = nums[i];
            length++;
        }
    }

    return length > numsSize ? numsSize : length;
}
// @lc code=end
