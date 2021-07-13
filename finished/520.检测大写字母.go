/*
 * @lc app=leetcode.cn id=520 lang=golang
 *
 * [520] 检测大写字母
 *
 * https://leetcode-cn.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (56.13%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 64.2K
 * Testcase Example:  '"USA"'
 *
 * 给定一个单词，你需要判断单词的大写使用是否正确。
 *
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 *
 *
 * 全部字母都是大写，比如"USA"。
 * 单词中所有字母都不是大写，比如"leetcode"。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
 *
 *
 * 否则，我们定义这个单词没有正确使用大写字母。
 *
 * 示例 1:
 *
 *
 * 输入: "USA"
 * 输出: True
 *
 *
 * 示例 2:
 *
 *
 * 输入: "FlaG"
 * 输出: False
 *
 *
 * 注意: 输入是由大写和小写拉丁字母组成的非空单词。
 *
 */

// @lc code=start
package main

// 先统计大写字母的个数再分情况讨论
func detectCapitalUse(word string) bool {
	if len(word) == 0 {
		return true
	}

	cnt := 0
	for _, w := range word {
		if w >= 'A' && w <= 'Z' {
			cnt++
		}
	}
	if cnt == len(word) {
		return true
	}
	if cnt == 1 && word[0] >= 'A' && word[0] <= 'Z' {
		return true
	}
	return cnt == 0
}

// @lc code=end
