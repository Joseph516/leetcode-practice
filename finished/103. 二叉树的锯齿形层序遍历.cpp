/*
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历
。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目在范围 [0, 2000] 内
-100 <= Node.val <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;  // 最终结果
    vector<int> layer;        // 每一层结果
    queue<TreeNode*> q;
    if (root) {
      q.push(root);
    }
    bool left2right = true;
    TreeNode* last = root;
    while (!q.empty()) {
      TreeNode* cur = q.front();
      layer.push_back(cur->val);
      q.pop();
      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
      if (cur == last) {
        if (!left2right) {
          // 可以用双端队列从不同的方向添加元素，代替reverse
          reverse(layer.begin(), layer.end());
        }
        left2right = !left2right;
        ans.push_back(layer);
        layer.clear();
        last = q.back();
      }
    }
    return ans;
  }
};