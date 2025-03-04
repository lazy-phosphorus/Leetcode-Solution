/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 轮转数组
 */

// @lc code=start

static inline void swap(int *restrict a, int *restrict b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int *nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        swap(nums + left, nums + right);
        left++;
        right--;
    }

    left = 0;
    right = k % numsSize - 1;
    while (left < right) {
        swap(nums + left, nums + right);
        left++;
        right--;
    }

    left = k % numsSize;
    right = numsSize - 1;
    while (left < right) {
        swap(nums + left, nums + right);
        left++;
        right--;
    }
}
// @lc code=end
