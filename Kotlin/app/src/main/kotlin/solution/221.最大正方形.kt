/*
 * @lc app=leetcode.cn id=221 lang=kotlin
 *
 * [221] 最大正方形
 */

package solution221

// @lc code=start
import kotlin.math.max
import kotlin.math.min

class Solution {
    fun maximalSquare(matrix: Array<CharArray>): Int {
        var result = 0
        var cache = Array(matrix.size) { IntArray(matrix[0].size) { 0 } }

        for (i in 0 until matrix.size) {
            for (j in 0 until matrix[i].size) {
                if (matrix[i][j] == '1') {
                    cache[i][j] =
                            if (i == 0 || j == 0) {
                                1
                            } else {
                                arrayOf(cache[i - 1][j - 1], cache[i - 1][j], cache[i][j - 1])
                                        .min() + 1
                            }
                    result = max(result, cache[i][j])
                }
            }
        }
        return result * result
    }
}
// @lc code=end
