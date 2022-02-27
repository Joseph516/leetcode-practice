/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
 

提示：

数组长度 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  // 关键：二叉搜索树，任意节点大于其左节点，小于其右节点
  bool verifyPostorder(vector<int>& postorder) {
    if (postorder.empty()) return true;
    return compareDfs(postorder, 0, postorder.size() - 1);
  }

  bool compareDfs(const vector<int>& postorder, int left, int right) {
    if (left == right) return true;

    int val_root = postorder[right];
    // 找左子树
    int left_right = left;
    while (left_right < right && postorder[left_right] < val_root) {
      left_right++;
    }
    // 优化2:可以在这里，从left_right开始遍历右侧是否存在小于val_root的节点，存在返回false
    //      从而代替right_left - left_right <= 1，并且可省去对右子树的while查找
    if (left_right != left) left_right--;

    // 找右子树
    int right_left = right - 1;
    while (right_left >= left && postorder[right_left] > val_root) {
      right_left--;
    }
    if (right_left != right - 1) right_left++;

    // 递归判断
    return right_left - left_right <= 1 &&
           compareDfs(postorder, left, left_right) &&
           compareDfs(postorder, right_left, right - 1);
  }
};