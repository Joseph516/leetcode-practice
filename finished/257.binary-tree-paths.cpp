/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (44.17%)
 * Total Accepted:    200K
 * Total Submissions: 451.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string s;
    // []
    if (root == NULL) {
      return res;
    }

    s += to_string(root->val);
    // one node
    if (root->left == NULL && root->right == NULL) {
      // leaf node
      res.push_back(s);
      return res;
    }
    // normal  mode
    if (root->left != NULL) {
      addPath(root->left, res, s);
    }
    if (root->right != NULL) {
        addPath(root->right, res, s);
    }
    return res;
  }

  void addPath(TreeNode* root, vector<string>& res, string s) {
    s += "->" + to_string(root->val);
    if (root->left == NULL && root->right == NULL) {
      // leaf node
      res.push_back(s);
      return;
    }
    if (root->left != NULL) {
      addPath(root->left, res, s);
    }
    if (root->right != NULL) {
      addPath(root->right, res, s);
    }
  }
};
