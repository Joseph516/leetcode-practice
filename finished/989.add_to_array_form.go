package main

import "fmt"

// 向前插入
func addToArrayForm(A []int, K int) []int {
	n := len(A)
	flag := 0     // 进位
	var res []int // 结果

	for i := n - 1; i >= 0 || K != 0; {
		// 计算和
		tmpVal := flag
		if i >= 0 {
			tmpVal += A[i]
			i--
		}
		if K != 0 {
			adderK := K % 10
			K /= 10
			tmpVal += adderK
		}
		// 判断进位
		if tmpVal >= 10 {
			tmpVal -= 10
			flag = 1
		} else {
			flag = 0
		}
		// 保存至结果数组
		res = append([]int{tmpVal}, res...)
	}
	if flag != 0 {
		res = append([]int{flag}, res...)
	}
	return res
}

// 向后插入节省时间
func addToArrayForm2(A []int, K int) []int {
	n := len(A)
	var res []int // 结果，逆序

	// 先把A[]计算完
	for i := n - 1; i >= 0; i-- {
		tmpVal := A[i] + K%10
		K /= 10
		if tmpVal >= 10 {
			tmpVal -= 10
			K++
		}
		res = append(res, tmpVal)
	}

	// 把K加完
	for ; K > 0; K /= 10 {
		res = append(res, K%10)
	}

	// 反转数组
	reverse(res)
	return res
}

func reverse(A []int) {
	for i, n := 0, len(A); i < n/2; i++ {
		A[i], A[n-1-i] = A[n-1-i], A[i]
	}
}

func main() {
	A := []int{0}
	K := 23
	fmt.Println(addToArrayForm(A, K))
}
