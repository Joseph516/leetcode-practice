/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (53.81%)
 * Likes:    796
 * Dislikes: 0
 * Total Accepted:    127.1K
 * Total Submissions: 236.3K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums
 * ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 *
 *
 * 进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    // 去掉重复数字
    set<int> m;
    for (int i = 0; i < nums.size(); i++) {
      m.insert(nums[i]);
    }
    // 优化：可以直接操作set，而不用生成nums_sort
    vector<int> nums_sort;
    for (auto& p : m) {
      nums_sort.push_back(p);
    }

    int n = nums_sort.size();
    if (n < 2) {
      return n;
    }

    int max_len = 0;
    int left = 0, right = 1;  // 左右位置
    while (right < n) {
      if (nums_sort[right] == nums_sort[right - 1] + 1) {
        right++;
      } else {
        if (right - left > max_len) {
          max_len = right - left;
        }
        left = right;
        right++;
      }
    }
    if (right - left > max_len) {
      max_len = right - left;
    }
    return max_len;
  }
};
// @lc code=end
