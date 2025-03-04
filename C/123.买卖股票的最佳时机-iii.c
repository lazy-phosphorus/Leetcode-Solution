/*
 * @lc app=leetcode.cn id=123 lang=c
 *
 * [123] 买卖股票的最佳时机 III
 */

#include <stdbool.h>

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int *prices, int pricesSize) {
    int first_hold = -prices[0], second_hold = -prices[0], first_sold = 0,
        second_sold = 0;

    for (int i = 1; i < pricesSize; i++) {
        first_hold = max(first_hold, -prices[i]);
        first_sold = max(first_hold + prices[i], first_sold);
        second_hold = max(second_hold, first_sold - prices[i]);
        second_sold = max(second_hold + prices[i], second_sold);
    }
    return second_sold;
}
// @lc code=end
