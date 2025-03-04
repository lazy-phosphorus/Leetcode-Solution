/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
int minSubArrayLen(int target, int *nums, int numsSize) {
    int left = 0, right = 0, sum = 0;

    while (right < numsSize) {
        sum += nums[right];
        right++;
        if (sum >= target) break;
    }
    if (sum < target) return 0;

    while (right < numsSize) {
        sum += nums[right] - nums[left];
        left++;
        right++;
        while (left < numsSize && sum - nums[left] >= target) {
            sum -= nums[left];
            left++;
        }
    }

    while (left < numsSize && sum - nums[left] >= target) {
        sum -= nums[left];
        left++;
    }
    return right - left;
}

// @lc code=end
