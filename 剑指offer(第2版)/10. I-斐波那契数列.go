/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5


提示：

0 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

import (
	"fmt"
	"os"
	"strconv"
)

var mod int = int(1e9 + 7)

// O(n)
func fib(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	f0, f1 := 0, 1
	f2 := 0
	for i := 2; i <= n; i++ {
		f2 = (f0 + f1) % mod
		f0 = f1
		f1 = f2
	}
	return f2
}

// O(nlogn)
func fib2(n int) int {
	if n == 0 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	mat := []int{1, 1, 1, 0}

	var res []int
	n -= 1 // 求基矩阵的n-1次方
	res = calMatN(n, mat)

	return res[0]
}

// calMatN: 递归计算mat的n次方
func calMatN(n int, mat []int) []int {
	if n == 1 {
		return mat
	}
	if n%2 == 0 {
		// a^(n/2)*a^(n/2)
		return matMultiply(calMatN(n/2, mat), calMatN(n/2, mat))
	} else {
		n -= 1
		// a*a^(n/2)*a^(n/2)
		return matMultiply(mat, matMultiply(calMatN(n/2, mat), calMatN(n/2, mat)))
	}
}

// matMultiply: 简易版矩阵乘法
func matMultiply(a, b []int) []int {
	c := make([]int, 4)
	c[0] = (a[0]*b[0] + a[1]*b[2]) % mod
	c[1] = (a[0]*b[1] + a[1]*b[3]) % mod
	c[2] = (a[2]*b[0] + a[3]*b[2]) % mod
	c[3] = (a[2]*b[1] + a[3]*b[3]) % mod
	return c
}

func main() {
	var n int
	args := os.Args
	if args == nil || len(args) < 2 {
		n = 2
	} else {
		n, _ = strconv.Atoi(args[1])
	}

	fmt.Println(fib(n))
	fmt.Println(fib2(n))
}
