/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

static inline int min(int a, int b) { return a > b ? b : a; }

int maxArea(int *height, int heightSize) {
    int result = 0, left = 0, right = heightSize - 1, min_h = 0;

    while (left < right) {
        if (min_h < min(height[left], height[right])) {
            min_h = min(height[left], height[right]);
            result = max(result, min_h * (right - left));
        }

        if (height[right] < height[left])
            right--;
        else
            left++;
    }

    return result;
}
// @lc code=end
