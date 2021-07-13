/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
 *
 * https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (52.73%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    17.7K
 * Total Submissions: 33.6K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给定一个二叉树，确定它是否是一个完全二叉树。
 *
 * 百度百科中对完全二叉树的定义如下：
 *
 * 若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1)
 * 的结点数都达到最大个数，第 h
 * 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含
 * 1~ 2^h 个节点。）
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[1,2,3,4,5,6]
 * 输出：true
 * 解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3}
 * 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[1,2,3,4,5,null,7]
 * 输出：false
 * 解释：值为 7 的结点没有尽可能靠向左侧。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中将会有 1 到 100 个结点。
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <queue>
using namespace std;

class Solution {
 public:
  // 层序遍历
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *cur;  // 当前节点
    while (!q.empty()) {
      cur = q.front();
      q.pop();

      // 错误情况1：左子树为空，右子树存在
      if (cur->left == nullptr && cur->right != nullptr) {
        return false;
      }

      // 节点入队
      if (cur->left != nullptr) {
        q.push(cur->left);
      }
      if (cur->right != nullptr) {
        q.push(cur->right);
      }
      
      // 错误情况2：当左侧子树为空时，右侧子树必须全部为空。
      if (cur->left == nullptr || cur->right == nullptr) {
        while (!q.empty()) {
          cur = q.front();
          q.pop();
          if (cur->left || cur->right) {
            return false;
          }
        }
      }
    }
    return true;
  }

  // 完全二叉树: 0<=左子树深度-右子树深度<=1
  // 错误：该方法无法处理[1,2,3,5,null,7,8]的情况。
  bool isCompleteTree2(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return true;
    }
    int depth_left = depth(root->left);
    int depth_right = depth(root->right);
    if (depth_left < depth_right || depth_left > depth_right + 1) {
      return false;
    }
    return isCompleteTree(root->left) && isCompleteTree(root->right);
  }

  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    return max(depth(root->left), depth(root->right)) + 1;
  }
};
// @lc code=end
