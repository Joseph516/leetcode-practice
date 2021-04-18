/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]

限制：

0 <= 链表长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//  Definition for singly-linked list.
package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// 思路：反转链表再遍历
// 也可以先遍历出数组，然后对数组进行反转
// 或者遍历出链表的长度，然后数组从后向前保存链表的节点
func reversePrint(head *ListNode) []int {
	if head == nil {
		return []int{}
	}
	pre_head := &ListNode{} // Next默认为nil
	// 反转链表
	curr := head
	for curr != nil {
		next := curr.Next
		curr.Next = pre_head.Next
		pre_head.Next = curr
		curr = next
	}
	curr = pre_head.Next
	res := []int{}
	for curr != nil {
		res = append(res, curr.Val)
		curr = curr.Next
	}
	return res
}
