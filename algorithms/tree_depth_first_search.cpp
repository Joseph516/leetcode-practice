/**
 * Objective:Given a b-tree, do the depth-first-search(DFS) or traversal.
 * Appraoch: stack, no recursion.
 * Example:
 *        1
 *       / \
 *      2    3
 *     / \  / \
 *    4   5 6  7
 * Output: 
 * preorder: 1 2 4 5 3 6 7
 */

#include <iostream>
#include <stack>
using namespace std;

// tree node
class TreeNode {
  public:
  int data;
  TreeNode* left = NULL;
  TreeNode* right = NULL;

  public:
  TreeNode(int data)
      : data(data) {
  }
};

// depth-first-search
class DFS {
  public:
  void printDFS(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);
    // begins!
    while (!s.empty()) {
      TreeNode* temp = s.top();
      s.pop();
      // push right first
      if (temp->right != NULL) {
        s.push(temp->right);
      }
      if (temp->left != NULL) {
        s.push(temp->left);
      }
      // print data
      cout << temp->data << " ";
    }
  }
};

// test!
int main(void) {
  // build tree.
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  DFS test;
  cout << "Depth-First-Search: " << endl;
  test.printDFS(root);
}
