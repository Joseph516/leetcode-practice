/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (41.33%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    89.2K
 * Total Submissions: 213.3K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums
 * [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 *
 * 示例 2:
 *
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 *
 * 示例 3:
 *
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 *
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> duplicate;
    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
      auto search = duplicate.find(nums[i]);
      if (search != duplicate.end()) {
        return true;
      }
      duplicate.insert(nums[i]);
      if (duplicate.size() > k) {
        // deleteNum(duplicate, nums[i - k]);
        duplicate.erase(nums[i - k]);
      }
    }
    return false;
  }
  // 删除集合中指定的元素
  void deleteNum(unordered_set<int>& set, const int& key) {
    auto search = set.find(key);
    set.erase(search);
  }
};
// @lc code=end
