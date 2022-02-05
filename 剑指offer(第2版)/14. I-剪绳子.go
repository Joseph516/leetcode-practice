/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
提示：

2 <= n <= 58
注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

import (
	"flag"
	"fmt"
)

// 思路：动态规划
func cuttingRope(n int) int {
	// 注意 2 <= n <= 58，因此不作判断
	marr := make([]int, n+1)
	marr[0] = 0
	marr[1] = 1
	for i := 2; i <= n; i++ {
		mulValueMax := 0
		for k := 1; k <= i/2; k++ {
			// 两边都继续拆分求乘积
			mulValue := marr[k] * marr[i-k]
			if mulValue > mulValueMax {
				mulValueMax = mulValue
			}
			// 两边都不拆分求乘积
			mulValue = k * (i - k)
			if mulValue > mulValueMax {
				mulValueMax = mulValue
			}
			// 其中一边拆分求乘积
			mulValue = marr[k] * (i - k)
			if mulValue > mulValueMax {
				mulValueMax = mulValue
			}
			mulValue = k * marr[i-k]
			if mulValue > mulValueMax {
				mulValueMax = mulValue
			}
		}
		marr[i] = mulValueMax
	}
	return marr[n]
}

// 思路：动态规划，书上解法
func cuttingRope2(n int) int {
	if n == 2 {
		return 1
	}
	if n == 3 {
		return 2
	}

	marr := make([]int, n+1)
	marr[0] = 0
	marr[1] = 1
	marr[2] = 2 // 不拆时最大
	marr[3] = 3 // 不拆时最大
	for i := 4; i <= n; i++ {
		mulValueMax := 0
		for k := 1; k <= i/2; k++ {
			// 两边都继续拆分求乘积
			mulValue := marr[k] * marr[i-k]
			if mulValue > mulValueMax {
				mulValueMax = mulValue
			}
		}
		marr[i] = mulValueMax
	}
	return marr[n]
}

func main() {
	var n = flag.Int("n", 10, "intput n")
	flag.Parse()
	fmt.Println(cuttingRope(*n))
}
