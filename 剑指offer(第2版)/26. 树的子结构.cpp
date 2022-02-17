/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：

0 <= 节点个数 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // 解法1：
  // 题目节点存在存在重复值，需要多次比较
  // 根节点前序遍历直到第一个节点等于B的前序节点，然后开始依次比较
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!B || !A) {
      return false;
    }

    TreeNode* pb_cur = B;
    // 前序遍历A树
    TreeNode* pa_cur = A;
    std::stack<TreeNode*> st_a;
    while (!st_a.empty() || pa_cur) {
      if (pa_cur) {
        if (pa_cur->val == pb_cur->val) {
          bool res = compareDFS(pa_cur, pb_cur);
          if (res) return true;
        }
        st_a.push(pa_cur);
        pa_cur = pa_cur->left;
      } else {
        pa_cur = st_a.top();
        st_a.pop();
        pa_cur = pa_cur->right;
      }
    }
    return false;
  }

  // isSubStructure递归
  bool isSubStructure2(TreeNode* A, TreeNode* B) {
    if (!B || !A) {
      return false;
    }

    return compareDFS(A, B) || isSubStructure2(A->left, B) ||
           isSubStructure2(A->right, B);
  }

  bool compareDFS(TreeNode* const pa, TreeNode* const pb) {
    if (!pb) return true;
    if (!pa && pb) return false;
    return pa->val == pb->val && compareDFS(pa->left, pb->left) &&
           compareDFS(pa->right, pb->right);
  }
};