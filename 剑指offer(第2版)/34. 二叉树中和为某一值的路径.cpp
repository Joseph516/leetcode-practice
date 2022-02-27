/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点
路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

示例 1：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：

输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]

提示：

树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode *root, int target) {
    vector<vector<int>> paths;
    if (!root) return paths;

    vector<int> path;  // 保存单个路径

    pathSumDfs(root, target, paths, path, 0);
    return paths;
  }

  // 注意：路径必须到叶子节点
  void pathSumDfs(TreeNode *root, int target, vector<vector<int>> &paths,
                  vector<int> &path, int sum) {
    if (!root) return;

    sum += root->val;
    path.push_back(root->val);

    // 到达叶子节点
    if (root->left == nullptr && root->right == nullptr) {
      if (sum == target) {
        paths.push_back(path);
      }
      // path.pop_back();  // 由于path是引用，需要去除末尾并找寻新的路径
      // return;
    }

    pathSumDfs(root->left, target, paths, path, sum);
    pathSumDfs(root->right, target, paths, path, sum);
    path.pop_back();  // 由于path是引用，需要去除末尾并找寻新的路径
  }
};