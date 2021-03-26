/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (54.17%)
 * Likes:    1301
 * Dislikes: 0
 * Total Accepted:    289.2K
 * Total Submissions: 533.8K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 *
 *
 *
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以运用递归和迭代两种方法解决这个问题吗？
 *
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;

// 关键点：同时交叉check两个节点
class Solution {
 public:
  bool isSymmetric(TreeNode *root) { return check(root, root); }

  bool check(TreeNode *u, TreeNode *v) {
    if (!u && !v) {
      return true;
    }
    // 一个节点为null，一个不为null
    if (!u || !v) {
      return false;
    }
    return u->val == v->val && check(u->left, v->right) &&
           check(u->right, v->left);
  }

  bool check(TreeNode *u, TreeNode *v) {
    queue<TreeNode *> q;
    q.push(u); q.push(v);
    while(!q.empty()) {
      u = q.front(); q.pop();
      v = q.front(); q.pop();
      if (!u && !v) {
        continue;
      }
      if ((!u || !v) || (u->val != v->val)){
        return false;
      }
      q.push(u->left);
      q.push(v->right);
      q.push(u->right);
      q.push(v->left);
    }
    return true;
  }

};
// @lc code=end
