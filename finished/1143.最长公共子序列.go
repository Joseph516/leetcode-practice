/*
 * @lc app=leetcode.cn id=1143 lang=golang
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (61.31%)
 * Likes:    450
 * Dislikes: 0
 * Total Accepted:    92.6K
 * Total Submissions: 149.8K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 *
 * 一个字符串的 子序列
 * 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 *
 *
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 *
 *
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：text1 = "abcde", text2 = "ace"
 * 输出：3
 * 解释：最长公共子序列是 "ace" ，它的长度为 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc" ，它的长度为 3 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * text1 和 text2 仅由小写英文字符组成。
 *
 *
 */

// @lc code=start
package main

func longestCommonSubsequence(text1 string, text2 string) int {
	len1 := len(text1)
	len2 := len(text2)

	// 动态规划数组
	// dp[i][j]表示text1的0-i和text2的0-j的最长子序列
	dp := make([][]int, len1+1)
	for i := 0; i <= len1; i++ {
		dp[i] = make([]int, len2+1)
	}
	// 初始化第一行和第一列
	for i := 0; i < len2; i++ {
		if text1[0] == text2[i] {
			for j := i; j < len2; j++ {
				dp[1][j+1] = 1
			}
			break
		}
	}
	for i := 0; i < len1; i++ {
		if text1[i] == text2[0] {
			for j := i; j < len1; j++ {
				dp[j+1][1] = 1
			}
			break
		}
	}
	// 依次开始动态规划
	for i := 1; i < len1; i++ {
		for j := 1; j < len2; j++ {
			if text1[i] == text2[j] {
				dp[i+1][j+1] = dp[i][j] + 1
			} else {
				dp[i+1][j+1] = MaxInt(dp[i][j+1], dp[i+1][j])
			}
		}
	}
	return dp[len1][len2]
}

func MaxInt(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// @lc code=end
