/*
 * @lc app=leetcode.cn id=474 lang=c
 *
 * [474] 一和零
 */

#include <malloc.h>
#include <string.h>

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int findMaxForm(char **strs, int strsSize, int m, int n) {
    int result = 0, **dp = (int **)calloc(m + 1, sizeof(int *));

    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }

    for (int i = 0; i < strsSize; i++) {
        int one = 0, zero = 0;
        for (int j = 0; j < strlen(strs[i]); j++) {
            if (strs[i][j] == '0') zero++;
            if (strs[i][j] == '1') one++;
        }
        for (int j = m; j >= zero; j--) {
            for (int k = n; k >= one; k--) {
                dp[j][k] = max(dp[j - zero][k - one] + 1, dp[j][k]);
            }
        }
    }
    result = dp[m][n];

    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
// @lc code=end
