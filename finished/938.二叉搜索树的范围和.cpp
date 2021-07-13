/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 *
 * https://leetcode-cn.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (78.05%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    83.4K
 * Total Submissions: 102.1K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * 给定二叉搜索树的根结点 root，返回值位于范围 [low, high]
 * 之间的所有结点的值的和。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
 * 输出：32
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 2 * 10^4] 内
 * 1
 * 1
 * 所有 Node.val 互不相同
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
 public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (root == nullptr) {
      return 0;
    }
    if (root->val >= low && root->val <= high) {
      return root->val + rangeSumBST(root->left, low, high) +
             rangeSumBST(root->right, low, high);
    } else if (root->val < low) {
      return rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
      return rangeSumBST(root->left, low, high);
    }
    return 0;
  }
};
// @lc code=end
