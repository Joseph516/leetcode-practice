/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

为了让您更好地理解问题，以下面的二叉搜索树为例：

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

注意：本题与主站 426
题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

注意：此题对比原题有改动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = nullptr;
    right = nullptr;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

#include <stack>
using namespace std;

class Solution {
 public:
  // 排序二叉树的中序遍历是升序的
  // 这道题实际上是建立二叉线索树
  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;

    stack<Node*> st;
    Node* cur = root;
    Node* root_new = nullptr;
    Node* prev = nullptr;
    while (!st.empty() || cur) {
      if (cur) {
        st.push(cur);
        cur = cur->left;
      } else {
        Node* st_top = st.top();
        st.pop();
        // 设置最左侧节点为新的头节点
        if (!root_new) {
          root_new = st_top;
        }
        // 前序节点
        st_top->left = prev;
        prev = st_top;
        // 后序节点
        if (st_top->right == nullptr) {
          if (st.empty()) {
            // 最优一个节点的后序指向第一个节点
            st_top->right = root_new;
          } else {
            st_top->right = st.top();
          }
          cur = nullptr;
        } else {
          // 寻找后序节点
          Node * next = st_top->right;
          while(next) {
              st.push(next);
              next = next->left;
          }
          st_top->right = st.top();
          cur = nullptr;
        }
      }
    }
    // 第一个节点的前序设置为最后一个节点
    root_new->left = prev;
    return root_new;
  }
};