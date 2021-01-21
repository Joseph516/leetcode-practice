package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var p, q *ListNode

	res := &ListNode{} // 头结点
	tail := res        // 尾指针
	flag := 0          // 进位
	for p, q = l1, l2; p != nil || q != nil; {
		// 处理长度不等的列表
		pVal := 0
		qVal := 0
		if p != nil {
			pVal = p.Val
			p = p.Next
		}
		if q != nil {
			qVal = q.Val
			q = q.Next
		}
		// 按位相加
		tmpVal := pVal + qVal + flag
		// 处理进位
		if tmpVal < 10 {
			flag = 0
		} else {
			tmpVal -= 10
			flag = 1
		}
		tmpNode := &ListNode{Val: tmpVal}
		// 尾插法
		tail.Next = tmpNode
		tail = tmpNode
	}
	// 处理可能的进位
	if flag != 0 {
		tmpNode := &ListNode{Val: flag}
		tail.Next = tmpNode
	}
	return res.Next
}

func main() {
	node1 := &ListNode{
		Val: 1,
	}
	node2 := &ListNode{
		Val: 2,
	}
	node1.Next = node2

	node3 := &ListNode{
		Val: 3,
	}
	node4 := &ListNode{
		Val: 4,
	}
	node5 := &ListNode{
		Val: 5,
	}
	node3.Next = node4
	node4.Next = node5

	_ = addTwoNumbers(node1, node3)
}
