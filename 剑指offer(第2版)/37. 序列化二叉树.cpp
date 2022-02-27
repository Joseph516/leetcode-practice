/*
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
 

注意：本题与主站 297
题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
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

#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Codec0 {
 public:
  // Encodes a tree to a single string.
  // 节点值可能是负数，讲字符用逗号分隔
  // 这种方法无法处理节点值重复的情况
  string serialize(TreeNode* root) {
    if (!root) return string();
    stack<TreeNode*> st;
    TreeNode* cur = root;

    string pre_order, in_order;  // 前序中序
    while (!st.empty() || cur) {
      if (cur) {
        if (!pre_order.empty()) pre_order += ",";
        pre_order += to_string(cur->val);
        st.push(cur);
        cur = cur->left;
      } else {
        TreeNode* st_top = st.top();
        st.pop();
        if (!in_order.empty()) in_order += ",";
        in_order += to_string(st_top->val);
        cur = st_top->right;
      }
    }
    return pre_order + "," + in_order;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;

    vector<int> pre_order, in_order;
    int n = (data.size() + 1) >> 2, i = 1;
    string tmp = "";
    for (auto& v : data) {
      if (v != ',') {
        tmp += v;
      } else {
        if (i <= n) {
          pre_order.push_back(stoi(tmp));
        } else {
          in_order.push_back(stoi(tmp));
        }
        tmp = "";
        i++;
      }
    }
    in_order.push_back(stoi(tmp));

    return buildDfs(pre_order, 0, pre_order.size() - 1, in_order, 0,
                    in_order.size() - 1);
  }

  TreeNode* buildDfs(vector<int>& pre_order, int pi, int pj,
                     vector<int>& in_order, int ii, int ij) {
    if (pi > pj || ii > ij) {
      return nullptr;
    }

    // 找到根节点位置
    int i = ii;
    while (i <= ij && pre_order[pi] != in_order[i]) {
      i++;
    }
    TreeNode* root = new TreeNode(pre_order[pi]);

    root->left = buildDfs(pre_order, pi + 1, i - ii + pi, in_order, ii, i - 1);
    root->right = buildDfs(pre_order, pj - ij + i + 1, pj, in_order, i + 1, ij);

    return root;
  }
};

class Codec {
 public:
  // Encodes a tree to a single string.
  // 节点值可能是负数，讲字符用逗号分隔
  string serialize(TreeNode* root) {
    if (!root) return string();
    stack<TreeNode*> st;
    TreeNode* cur = root;

    string pre_order;  // 前序，空节点用null代替
    while (!st.empty() || cur) {
      if (cur) {
        if (!pre_order.empty()) pre_order += ",";
        pre_order += to_string(cur->val);
        st.push(cur);
        cur = cur->left;
      } else {
        pre_order += ",null";
        TreeNode* st_top = st.top();
        st.pop();
        cur = st_top->right;
      }
    }
    return pre_order + ",null";
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    size_t idx = 0;
    return deserializeDfs(data, idx);
  }

  // 递归构建，注意idx是引用
  TreeNode* deserializeDfs(const string& data, size_t& idx) {
    string tmp = "";
    while (idx < data.size() && data[idx] != ',') {
      tmp += data[idx];
      idx++;
    }
    idx++; // 跳过逗号
    TreeNode* root = nullptr;
    if (tmp != "null") {
      root = new TreeNode(stoi(tmp));
      root->left = deserializeDfs(data, idx);
      root->right = deserializeDfs(data, idx);
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));