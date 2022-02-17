/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

限制：

0 <= 节点个数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // 需要辅助空间
  TreeNode* mirrorTree(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* new_root = new (TreeNode);
    buildTree(root, new_root);
    return new_root;
  }

  void buildTree(TreeNode* root, TreeNode* new_root) {
    new_root->val = root->val;
    if (root->left) {
      TreeNode* node = new (TreeNode);
      new_root->right = node;
      buildTree(root->left, node);
    }
    if (root->right) {
      TreeNode* node = new (TreeNode);
      new_root->left = node;
      buildTree(root->right, node);
    }
  }

  // 原地解法
  TreeNode* mirrorTree(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* tmp_left = mirrorTree(root->left);
    TreeNode* tmp_right = mirrorTree(root->right);
    root->left = tmp_right;
    root->right = tmp_left;
    return root;
  }
};