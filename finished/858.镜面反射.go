/*
 * @lc app=leetcode.cn id=858 lang=golang
 *
 * [858] 镜面反射
 *
 * https://leetcode-cn.com/problems/mirror-reflection/description/
 *
 * algorithms
 * Medium (54.90%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 4.3K
 * Testcase Example:  '2\n1'
 *
 * 有一个特殊的正方形房间，每面墙上都有一面镜子。除西南角以外，每个角落都放有一个接受器，编号为 0， 1，以及 2。
 *
 * 正方形房间的墙壁长度为 p，一束激光从西南角射出，首先会与东墙相遇，入射点到接收器 0 的距离为 q 。
 *
 * 返回光线最先遇到的接收器的编号（保证光线最终会遇到一个接收器）。
 *
 *
 *
 * 示例：
 *
 *
 * 输入： p = 2, q = 1
 * 输出： 2
 * 解释： 这条光线在第一次被反射回左边的墙时就遇到了接收器 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start
package main

func mirrorReflection(p int, q int) int {
	var g = gcd(p, q)
	var k_lr, k_ud int // 左右、上下翻转次数
	k_lr = p / g
	k_lr %= 2
	k_ud = q / g
	k_ud %= 2
	if k_lr == 1 && k_ud == 1 {
		return 1
	}
	if k_lr == 1 {
		return 0
	} else {
		return 2
	}
}

// 求最大公约数
func gcd(p, q int) int {
	if p == 0 {
		return q
	}
	return gcd(q%p, p)
}

// @lc code=end
