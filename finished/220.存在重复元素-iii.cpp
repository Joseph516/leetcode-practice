/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 *
 * https://leetcode-cn.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (26.59%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    54.8K
 * Total Submissions: 192.2K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和
 * j，使得 abs(nums[i] - nums[j]) ，同时又满足 abs(i - j)  。
 *
 * 如果存在则返回 true，不存在返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3,1], k = 3, t = 0
 * 输出：true
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,0,1,1], k = 1, t = 2
 * 输出：true
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,5,9,1,5,9], k = 2, t = 3
 * 输出：false
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -2^31
 * 0
 * 0
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // 使用有序集合
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> pre_nums;  // int做减法会溢出
    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
      // 查找首个>=nums[i]-t的数
      auto search = pre_nums.lower_bound((long)nums[i] - t);
      if (search != pre_nums.end() && (*search) <= (long)nums[i] + t) {
        return true;
      }

      pre_nums.insert(nums[i]);
      if (pre_nums.size() > k) {
        pre_nums.erase(nums[i - k]);
      }
    }
    return false;
  }

  // 超时，51/54
  bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
    unordered_set<long> pre_nums;  // int做减法会溢出
    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
      // 查找满足条件的元素
      for (auto it = pre_nums.begin(); it != pre_nums.end(); it++) {
        if (abs(nums[i] - (*it)) <= t) {
          return true;
        }
      }
      pre_nums.insert(nums[i]);
      if (pre_nums.size() > k) {
        // deleteNum(pre_nums, nums[i - k]);
        pre_nums.erase(nums[i - k]);
      }
    }
    return false;
  }

  // 删除集合中指定的元素
  void deleteNum(unordered_set<long>& set, const int& key) {
    auto search = set.find(key);
    set.erase(search);
  }
};

int main() {
  vector<int> nums{-2147483648, 2147483647};
  Solution test;
  test.containsNearbyAlmostDuplicate(nums, 1, 1);
}
// @lc code=end
