/*
 * @lc app=leetcode.cn id=188 lang=kotlin
 *
 * [188] 买卖股票的最佳时机 IV
 */

package solution188

// @lc code=start
import kotlin.math.max

class Solution {
    fun maxProfit(k: Int, prices: IntArray): Int {
        val soldProfit = IntArray(k) { 0 }
        val holdProfit = IntArray(k) { -prices[0] }

        for (i in 0 until prices.size) {
            for (j in 0 until k) {
                if (j == 0) holdProfit[j] = max(-prices[i], holdProfit[j])
                else holdProfit[j] = max(soldProfit[j - 1] - prices[i], holdProfit[j])

                soldProfit[j] = max(prices[i] + holdProfit[j], soldProfit[j])
            }
        }

        return soldProfit.max()
    }
}
// @lc code=end
