/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:

现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。

限制：

0 <= n <= 1000
0 <= m <= 1000

注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

// 采用双指针，从右上角开始搜索（也可以从左下角开始搜索）
func findNumberIn2DArray(matrix [][]int, target int) bool {
	n := len(matrix)
	if n == 0 {
		return false
	}
	m := len(matrix[0])
	i, j := 0, m-1
	// 从右上角开始搜索
	for i <= n-1 && j >= 0 {
		if matrix[i][j] == target {
			return true
		} else if matrix[i][j] < target {
			j--
		} else {
			i++
		}
	}
	return false
}

// 二分查找无法解决重复行的问题
// func findNumberIn2DArray(matrix [][]int, target int) bool {
// 	n := len(matrix)
// 	if n == 0 {
// 		return false
// 	}
// 	m := len(matrix[0])
// 	// 找到target所在的列
// 	left, right := 0, m-1
// 	for left < right {
// 		mid := left + (right-left)>>1
// 		if matrix[0][mid] == target {
// 			return true
// 		} else if matrix[0][mid] > target {
// 			right = mid - 1
// 		} else if matrix[m-1][mid] < target {
// 			left = mid + 1
// 		} else {
// 			left = mid
// 		}
// 	}
// 	// 找到target所在的行
// 	col := left
// 	left, right = 0, n-1
// 	for left < right {
// 		mid := left + (right-left)>>1
// 		if matrix[mid][col] == target {
// 			return true
// 		} else if matrix[mid][col] > target {
// 			right = mid - 1
// 		} else {
// 			left = mid + 1
// 		}
// 	}
// 	return false
// }
