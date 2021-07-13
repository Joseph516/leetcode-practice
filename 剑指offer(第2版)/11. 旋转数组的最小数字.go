/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0
注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

// minArray 输出数组中的最小值
func minArray(numbers []int) int {
	// 正序
	n := len(numbers)
	if n == 1 {
		return numbers[0]
	}
	if numbers[0] < numbers[n-1] {
		return numbers[0]
	}
	// 二分法
	l, h := 0, n-1
	for l < h-1 {
		m := l + (h-l)/2
		if numbers[l] == numbers[h] && numbers[m] == numbers[l] {
			// 特殊情况: [10,1,10,10,10]
			return orderSearch(numbers, l, h)
		}
		if numbers[m] >= numbers[l] {
			l = m
		}
		if numbers[m] <= numbers[h] {
			h = m
		}
	}
	return numbers[h]
}

// orderSearch 顺序搜索数组中的最小值
func orderSearch(numbers []int, indxA, indxB int) int {
	minVal := numbers[indxA]
	for i := indxA + 1; i < indxB; i++ {
		if numbers[i] < minVal {
			minVal = numbers[i]
		}
	}
	return minVal
}

// minArray2 方法2
func minArray2(numbers []int) int {
	n := len(numbers)
	l, h := 0, n-1
	for l < h {
		m := l + (h-l)/2
		if numbers[m] > numbers[h] {
			// 表示l-m位置肯定不是最小的
			l = m + 1
		} else if numbers[m] < numbers[h] {
			// 表示m+1-h都不是最小的
			h = m
		} else {
			// 特殊情况: [10,1,10,10,10]
			h--
		}
	}
	return numbers[l]
}
