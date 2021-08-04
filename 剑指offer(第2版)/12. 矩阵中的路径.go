/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。


示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false


提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
board 和 word 仅由大小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

func exist(board [][]byte, word string) bool {
	pathLen := 0
	rowLen, colLen := len(board), len(board[0])
	visited := make([][]bool, rowLen)
	for i := 0; i < rowLen; i++ {
		visited[i] = make([]bool, colLen)
	}

	for row := 0; row < rowLen; row++ {
		for col := 0; col < colLen; col++ {
			// 当hasPathCore为false时表示当前字母不是word的开头位置
			if hasPathCore(board, word, rowLen, colLen, row, col, pathLen, visited) {
				return true
			}
		}
	}
	return false
}

// 回溯法
func hasPathCore(board [][]byte, word string, rowLen, colLen, row, col, pathLen int, visited [][]bool) bool {
	if pathLen == len(word) {
		return true
	}
	hasPath := false
	if row >= 0 && row < rowLen && col >= 0 && col < colLen && board[row][col] == word[pathLen] && !visited[row][col] {
		pathLen++
		visited[row][col] = true
		hasPath = hasPathCore(board, word, rowLen, colLen, row+1, col, pathLen, visited) ||
			hasPathCore(board, word, rowLen, colLen, row-1, col, pathLen, visited) ||
			hasPathCore(board, word, rowLen, colLen, row, col+1, pathLen, visited) ||
			hasPathCore(board, word, rowLen, colLen, row, col-1, pathLen, visited)

		// 当前row和col对应字母不属于路径
		if !hasPath {
			pathLen--
			visited[row][col] = false
		}
	}
	return hasPath
}
