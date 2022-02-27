/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
 

提示：

节点总数 <= 1000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    TreeNode* tail = root;  // 每层最右侧节点
    vector<int> layer;      // 保存每层的节点值
    int layer_idx = 1;      // 层序号

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* cur = q.front();
      q.pop();
      layer.push_back(cur->val);
      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
      if (cur == tail) {
        tail = q.back();
        if (layer_idx & 1) {
          layer_idx = 0;
        } else {
          // 从右至左
          //   for (int i = 0; i < layer.size() / 2; i++) {
          //     swap(layer[i], layer[layer.size() - 1 - i]);
          //   }
          // 思路2:也可以用layer_idx控制先加入右节点再加入左节点
          reverse(layer.begin(), layer.end());
          layer_idx = 1;
        }
        ans.push_back(layer);
        layer.clear();
      }
    }
    return ans;
  }
};