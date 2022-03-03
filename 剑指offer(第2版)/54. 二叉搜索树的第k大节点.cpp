/*
给定一棵二叉搜索树，请找出其中第 k 大的节点的值。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
 

限制：

1 ≤ k ≤ 二叉搜索树元素个数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

#include <stack>
using namespace std;

class Solution {
 public:
  // 中序遍历并统计
  int kthLargest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    int max_val = 0;
    while (!st.empty() || cur) {
      if (cur) {
        st.push(cur);
        cur = cur->right;
      } else {
        TreeNode* tmp = st.top();
        st.pop();
        k--;
        if (k == 0) {
          max_val = tmp->val;
          break;
        }
        cur = tmp->left;
      }
    }
    return max_val;
  }
};