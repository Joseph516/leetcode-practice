/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
package main

var maxSize int = 10000

type CQueue struct {
	// 定义栈和栈顶指针
	s1   []int
	top1 int
	s2   []int
	top2 int
}

func Constructor() CQueue {
	return CQueue{
		s1:   make([]int, maxSize),
		top1: -1,
		s2:   make([]int, maxSize),
		top2: -1,
	}
}

func (this *CQueue) AppendTail(value int) {
	if this.top1 == maxSize-1 && this.top2 != -1 {
		// 栈满
		return
	}
	// 栈s1满，栈s2为空
	if this.top1 == maxSize-1 {
		for this.top1 != -1 {
			this.top2 += 1
			this.s2[this.top2] = this.s1[this.top1]
			this.top1 -= 1
		}
	}
	// 入队
	this.top1 += 1
	this.s1[this.top1] = value
}

func (this *CQueue) DeleteHead() int {
	// 队列为空
	if this.top1 == -1 && this.top2 == -1 {
		return -1
	}
	if this.top2 != -1 {
		res := this.s2[this.top2]
		this.top2 -= 1
		return res
	}
	// 将s1的元素全部出栈至s2
	for this.top1 != -1 {
		this.top2 += 1
		this.s2[this.top2] = this.s1[this.top1]
		this.top1 -= 1
	}
	// 出队
	res := this.s2[this.top2]
	this.top2 -= 1
	return res
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */

func main() {
	obj := Constructor()
	obj.AppendTail(1)
	_ = obj.DeleteHead()
}
