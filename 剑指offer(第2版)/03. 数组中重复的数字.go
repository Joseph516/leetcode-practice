/*
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

// 遍历2次的方法
func findRepeatNumber(nums []int) int {
	n := 100001
	cnt := make([]int, n)
	for _, v := range nums {
		cnt[v]++
	}
	for i := 0; i < len(cnt); i++ {
		if cnt[i] > 1 {
			return i
		}
	}
	return -1
}

// 遍历1次的方法，空间复杂度O(n)
func findRepeatNumber_v2(nums []int) int {
	cnt := make([]bool, 100001) // 初始化为false
	for _, v := range nums {
		if cnt[v] == true {
			// 若为true，表示前面已经出现了一次该元素
			return v
		} else {
			cnt[v] = true
		}
	}
	return -1
}

// 二分法，不需要辅助空间，空间复杂度O(1)
// 该算法有问题，无法解决[]int{0, 1, 2, 0, 4, 5, 6, 7, 8, 9}的情况
// 因为当1-m的数字不超过m时候，如1,1,3..m,仍然存在重复的数字
func findRepeatNumber_v3(nums []int) int {
	length := len(nums)
	if length <= 0 {
		return -1
	}
	start := 0
	end := length - 1
	for start <= end {
		mid := start + (end-start)>>1
		// 统计[start,mid]在整个数组中出现的次数
		cnt := 0
		for _, v := range nums {
			if v >= start && v <= mid {
				cnt++
			}
		}
		if end == start {
			if cnt > 1 {
				return start
			} else {
				break
			}
		}
		// 继续二分
		if cnt > (mid - start + 1) {
			end = mid
		} else {
			start = mid + 1
		}
	}
	return -1
}

func main() {
	nums := []int{0, 1, 2, 0, 4, 5, 6, 7, 8, 9}
	_ = findRepeatNumber_v3(nums)

}
