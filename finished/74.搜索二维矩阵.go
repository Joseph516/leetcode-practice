/*
 * @lc app=leetcode.cn id=74 lang=golang
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    111K
 * Total Submissions: 255.8K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 *
 *
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -10^4
 *
 *
 */

// @lc code=start
package main

import "sort"

// 二分查找
func searchMatrix(matrix [][]int, target int) bool {
	var low, high int
	var mid_row, mid_col int
	// 先按搜索行
	low = 0
	high = len(matrix) - 1
	for low <= high {
		mid_row = low + (high-low)/2
		if matrix[mid_row][0] == target {
			return true
		} else if matrix[mid_row][0] < target {
			low = mid_row + 1
		} else {
			high = mid_row - 1
		}
	}
	// 注意定位target的目标行
	if matrix[mid_row][0] > target && mid_row > 0 {
		mid_row -= 1
	}
	// 按列搜索
	low = 0
	high = len(matrix[0]) - 1
	for low <= high {
		mid_col = low + (high-low)/2
		if matrix[mid_row][mid_col] == target {
			return true
		} else if matrix[mid_row][mid_col] < target {
			low = mid_col + 1
		} else {
			high = mid_col - 1
		}
	}
	return false
}

// 一次二分搜索
func searchMatrix2(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	i := sort.Search(m*n, func(i int) bool { return matrix[i/n][i%n] >= target })
	return i < m*n && matrix[i/n][i%n] == target
}

// @lc code=end
