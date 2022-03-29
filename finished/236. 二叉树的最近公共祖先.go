/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

示例 1：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
示例 2：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
示例 3：

输入：root = [1,2], p = 1, q = 2
输出：1


提示：

树中节点数目在范围 [2, 105] 内。
-109 <= Node.val <= 109
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var fa map[int]*TreeNode
var vis map[int]bool

func dfs(root *TreeNode) {
	if root == nil {
		return
	}
	if root.Left != nil {
		fa[root.Left.Val] = root
		dfs(root.Left)
	}
	if root.Right != nil {
		fa[root.Right.Val] = root
		dfs(root.Right)
	}
}

// 保存父亲节点的方法
// 注意这里的每一个值是不一样的
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	fa = map[int]*TreeNode{}
	vis = map[int]bool{}
	fa[root.Val] = nil
	dfs(root)
	// 从p开始向上找
	for p != nil {
		vis[p.Val] = true
		p = fa[p.Val]
	}
	// 从q开始向上找
	for q != nil {
		if vis[q.Val] {
			return q
		}
		vis[q.Val] = true
		q = fa[q.Val]
	}
	return nil
}
