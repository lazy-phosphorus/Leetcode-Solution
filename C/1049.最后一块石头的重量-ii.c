/*
 * @lc app=leetcode.cn id=1049 lang=c
 *
 * [1049] 最后一块石头的重量 II
 */

#include <malloc.h>
#include <stdbool.h>

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int lastStoneWeightII(int *stones, int stonesSize) {
    int result = 0, sum = 0;
    bool *cache = NULL;
    for (int i = 0; i < stonesSize; i++) {
        sum += stones[i];
    }
    cache = (bool *)calloc(sum / 2 + 1, sizeof(bool));
    cache[0] = true;
    for (int i = 0; i < stonesSize; i++) {
        for (int j = sum / 2; j >= stones[i]; j--) {
            cache[j] = cache[j] || cache[j - stones[i]];
            if (cache[j]) result = max(j, result);
        }
    }

    free(cache);

    return sum - result * 2;
}
// @lc code=end
