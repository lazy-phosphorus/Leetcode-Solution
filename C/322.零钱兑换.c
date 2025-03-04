/*
 * @lc app=leetcode.cn id=322 lang=c
 *
 * [322] 零钱兑换
 */

#include <limits.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

// @lc code=start
static inline int min(int a, int b) { return a < b ? a : b; }

int coinChange(int *coins, int coinsSize, int amount) {
    int result = 0, *checked = (int *)calloc(amount + 1, sizeof(int));

    memset(checked, -1, sizeof(int) * (amount + 1));
    checked[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (i < coins[j] || checked[i - coins[j]] == -1) continue;

            if (checked[i] == -1)
                checked[i] = checked[i - coins[j]] + 1;
            else
                checked[i] = min(checked[i - coins[j]] + 1, checked[i]);
        }
    }

    result = checked[amount];
    free(checked);
    return result;
}
// @lc code=end
