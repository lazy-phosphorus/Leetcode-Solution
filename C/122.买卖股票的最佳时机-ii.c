/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

static inline int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int *prices, int pricesSize) {
    int hold_profit = -prices[0], sold_profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        hold_profit = max(hold_profit, sold_profit - prices[i]);
        sold_profit = max(hold_profit + prices[i], sold_profit);
    }

    return sold_profit;
}
// @lc code=end
