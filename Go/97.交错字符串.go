/*
* @lc app=leetcode.cn id=97 lang=golang
*
* [97] 交错字符串
 */
package main

// @lc code=start
func isInterleave(s1 string, s2 string, s3 string) bool {
	if len(s1)+len(s2) != len(s3) {
		return false
	}

	cache := make([]bool, len(s2)+1)
	for i := 0; i <= len(s2); i++ {
		cache[i] = false
	}
	cache[0] = true

	for i := 0; i <= len(s1); i++ {
		for j := 0; j <= len(s2); j++ {
			if i > 0 {
				cache[j] = cache[j] && s1[i-1] == s3[i+j-1]
			}

			if j > 0 {
				cache[j] = cache[j] || (cache[j-1] && s2[j-1] == s3[i+j-1])
			}
		}
	}

	return cache[len(s2)]
}

// @lc code=end
