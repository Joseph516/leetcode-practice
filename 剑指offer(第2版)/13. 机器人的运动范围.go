/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？



示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

func movingCount(m int, n int, k int) int {
	visited := make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}
	// visited切片引用传递，不需要像数组一样采用指针形式
	return movingCountDFS(0, 0, m, n, k, visited)
}

func movingCountDFS(i, j, m, n, k int, visited [][]bool) int {
	if !isPosLegal(i, j, m, n, k, visited) {
		return 0
	}
	cnt := 1
	cnt += movingCountDFS(i-1, j, m, n, k, visited)
	cnt += movingCountDFS(i+1, j, m, n, k, visited)
	cnt += movingCountDFS(i, j-1, m, n, k, visited)
	cnt += movingCountDFS(i, j+1, m, n, k, visited)
	return cnt
}

// isPosLegal 判断坐标[i, j]是否为有效
func isPosLegal(i, j, m, n, k int, visited [][]bool) bool {
	// 判断是否出界
	if i < 0 || i >= m {
		return false
	}
	if j < 0 || j >= n {
		return false
	}
	// 判断是否已经访问
	if visited[i][j] {
		return false
	} else {
		visited[i][j] = true
	}
	// 判断是否符合k值要求
	sum := 0
	for i != 0 {
		sum += i % 10
		i /= 10
	}
	for j != 0 {
		sum += j % 10
		j /= 10
	}
	return sum <= k
}
