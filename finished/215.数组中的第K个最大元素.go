/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4


提示：

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

// 注意这里是从大到小排序，不同于一般的从小到大排序
func partition(nums []int, low, high int) int {
	pivot := nums[low]
	for low < high {
		for low < high && nums[high] <= pivot {
			high--
		}
		nums[low] = nums[high]
		for low < high && nums[low] >= pivot {
			low++
		}
		nums[high] = nums[low]
	}
	nums[low] = pivot
	return low
}

func findKthLargestRecursive(nums []int, low, high, k int) int {
	pivot := partition(nums, low, high)
	if k == pivot {
		return nums[pivot]
	} else if k > pivot {
		return findKthLargestRecursive(nums, pivot+1, high, k)
	} else {
		return findKthLargestRecursive(nums, low, pivot-1, k)
	}
}

func findKthLargest(nums []int, k int) int {
	if k < 0 || k > len(nums) {
		return -1
	}
	// k-1表示从0开始计数
	return findKthLargestRecursive(nums, 0, len(nums)-1, k-1)
}
