/*
 * @lc app=leetcode.cn id=72 lang=golang
 *
 * [72] 编辑距离
 */

package main

// @lc code=start
func minDistance(word1 string, word2 string) int {
	cache := make([][]int, len(word1)+1)

	for i := 0; i <= len(word1); i++ {
		cache[i] = make([]int, len(word2)+1)
	}
	cache[0][0] = 0

	for i := 0; i <= len(word1); i++ {

		for j := 0; j <= len(word2); j++ {
			if i == 0 {
				cache[0][j] = j
				continue
			}

			if j == 0 {
				cache[i][0] = i
				continue
			}

			if word1[i-1] != word2[j-1] {
				cache[i][j] = min(cache[i-1][j], cache[i][j-1], cache[i-1][j-1]) + 1
			} else {
				cache[i][j] = min(cache[i-1][j]+1, cache[i][j-1]+1, cache[i-1][j-1])
			}
		}
	}
	return cache[len(word1)][len(word2)]
}

// @lc code=end
