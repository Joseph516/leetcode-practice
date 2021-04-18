/*
 * @lc app=leetcode.cn id=264 lang=golang
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (55.47%)
 * Likes:    509
 * Dislikes: 0
 * Total Accepted:    49.6K
 * Total Submissions: 89K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 *
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 *
 * 示例:
 *
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 *
 * 说明:
 *
 *
 * 1 是丑数。
 * n 不超过1690。
 *
 *
 */

// @lc code=start
package main

// 动态规划
// The key is how to maintain the order of the ugly numbers. Try a similar approach of merging
// from three sorted lists: L1, L2, and L3.
func nthUglyNumber(n int) int {
    dp := make([]int, n+1)
    dp[1] = 1
    p2, p3, p5 := 1, 1, 1
    for i := 2; i <= n; i++ {
        x2, x3, x5 := dp[p2]*2, dp[p3]*3, dp[p5]*5
        dp[i] = min(min(x2, x3), x5)
        // 判断是否相等，可以去重
        if dp[i] == x2 {
            p2++
        }
        if dp[i] == x3 {
            p3++
        }
        if dp[i] == x5 {
            p5++
        }
    }
    return dp[n]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}


// passed
// An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
func nthUglyNumber_v2(n int) int {
	if n <= 6 {
		return n
	}
	ugly_list := make([]int, n+1)
	candidates := []int{2, 3, 5}
	for i := 1; i <= 6; i++ {
		ugly_list[i] = i
	}
	for i := 7; i <= n; i++ {
		min_ugly := ugly_list[i-1] * 2
		// 从后向前找到最小的下一个丑数
		for j := i - 1; j > 0; j-- {
			for k := 0; k < 3; k++ {
				tmp_val := ugly_list[j] * candidates[k]
				if tmp_val > ugly_list[i-1] && tmp_val < min_ugly {
					min_ugly = tmp_val
				} else if tmp_val <= ugly_list[i] || tmp_val > min_ugly {
					break
				}
			}
		}
		ugly_list[i] = min_ugly
	}
	return ugly_list[n]
}

// 超出时间限制
func nthUglyNumber_v1(n int) int {
	ugly_cnt := 0
	i := 1
	for ugly_cnt != n {
		if isUgly(i) {
			ugly_cnt++
		}
		i++
	}
	return i - 1
}

func isUgly(n int) bool {
	if n <= 0 {
		return false
	}
	candidates := []int{2, 3, 5}
	for _, v := range candidates {
		for n%v == 0 {
			n /= v
		}
	}
	return n == 1
}

func main() {
	_ = nthUglyNumber(12)
}

// @lc code=end
