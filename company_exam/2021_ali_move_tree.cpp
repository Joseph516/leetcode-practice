/* 题目：平移满二叉树，阿里实习题目
给定一个数字n，表示二叉树的节点的值依次是1-n，给定一个值t，表示将该二叉树按照一定规则平移t个位置。
最后按照层序遍历输出节点的值。
平移规则：
1. 若该节点存在左子树，则将其与左子树的递归的所有左子树形成一个集合。
2. 将该集合中节点的值，平移t个位置。
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 用层序遍历依次输出树的节点
void display(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *curr = q.front();
    std::cout << curr->val << " ";
    q.pop();
    if (curr->left) {
      q.push(curr->left);
    }
    if (curr->right) {
      q.push(curr->right);
    }
  }
}

// 将集合内树节点的值平移t个位置
void move(vector<TreeNode *> &set, int t) {
  vector<TreeNode *>::size_type n = set.size();
  if (n == 0) {
    return;
  }
  t %= n;
  vector<int> tmp;
  for (vector<TreeNode *>::size_type i = 0; i < n; i++) {
    tmp.push_back(set[i]->val);
  }
  for (vector<TreeNode *>::size_type i = 0; i < n; i++) {
    set[i]->val = tmp[(i + t) % n];
  }
}

// 移动二叉树
void move_tree(int n, int t) {
  // 建立二叉树
  TreeNode *root = new TreeNode(1);
  queue<TreeNode *> q;
  q.push(root);
  for (int i = 2; i <= n;) {
    TreeNode *curr = q.front();
    q.pop();
    TreeNode *left = new TreeNode(i++);
    curr->left = left;
    q.push(left);
    if (i <= n) {
      TreeNode *right = new TreeNode(i++);
      curr->right = right;
      q.push(right);
    }
  }
  // 先序遍历
  stack<TreeNode *> s;
  TreeNode *curr = root;
  vector<TreeNode *> set;
  while (curr || !s.empty()) {
    if (curr) {
      s.push(curr);
      set.push_back(curr);
      curr = curr->left;
    } else {
      // 移动值
      move(set, t);
      set.clear();
      curr = s.top();
      s.pop();
      curr = curr->right;
    }
  }
  // 输出
  display(root);
}

int main() {
  move_tree(15, 2);
  return 0;
}