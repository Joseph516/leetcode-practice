/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。



示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4


提示：

1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 105
最多调用 2 * 105 次 get 和 put

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

package main

type Node struct {
	key, val   int
	prev, next *Node
}

type LRUCache struct {
	size       int
	capacity   int
	data       map[int]*Node
	head, tail *Node
}

func Constructor(capacity int) LRUCache {
	lruCache := LRUCache{
		size:     0,
		capacity: capacity,
		data:     make(map[int]*Node, capacity),
		// 头尾都设置占位，避免非空判断
		head: &Node{},
		tail: &Node{},
	}
	lruCache.head.next = lruCache.tail
	lruCache.tail.prev = lruCache.head

	return lruCache
}

func (this *LRUCache) Move(key int) *Node {
	// 摘除节点
	tmp := this.data[key]
	tmp.next.prev = tmp.prev
	tmp.prev.next = tmp.next
	// 将该节点移动到头部
	tmp.next = this.head.next
	tmp.prev = this.head
	this.head.next.prev = tmp
	this.head.next = tmp
	return tmp
}

func (this *LRUCache) Get(key int) int {
	if _, ok := this.data[key]; !ok {
		return -1
	} else {
		tmp := this.Move(key)
		return tmp.val
	}
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.data[key]; !ok {
		// 不存在
		if this.size == this.capacity {
			tmp := this.tail.prev
			// 移除末尾元素
			this.tail.prev = tmp.prev
			tmp.prev.next = this.tail
			// 释放空间
			delete(this.data, tmp.key)
			this.size -= 1
		}
		// 插入新节点
		tmp := &Node{
			key:  key,
			val:  value,
			prev: this.head,
			next: this.head.next,
		}
		this.head.next.prev = tmp
		this.head.next = tmp
		this.data[key] = tmp
		this.size += 1
	} else {
		// 存在，更新节点值
		this.data[key].val = value
		_ = this.Move(key)
	}
}
