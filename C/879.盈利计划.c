/*
 * @lc app=leetcode.cn id=879 lang=c
 *
 * [879] 盈利计划
 */

#include <malloc.h>

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int profitableSchemes(int n, int minProfit, int *group, int groupSize,
                      int *profit, int profitSize) {
    int **dp = (int **)calloc(n + 1, sizeof(int *)), result = 0;

    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)calloc(minProfit + 1, sizeof(int));
        dp[i][0] = 1;
    }

    for (int i = 0; i < profitSize; i++) {
        for (int j = n; j >= group[i]; j--) {
            for (int k = minProfit; k >= 0; k--) {
                dp[j][k] += dp[j - group[i]][max(k - profit[i], 0)];
                if (dp[j][k] > 1000000007) dp[j][k] -= 1000000007;
            }
        }
    }

    result = dp[n][minProfit];

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
// @lc code=end
