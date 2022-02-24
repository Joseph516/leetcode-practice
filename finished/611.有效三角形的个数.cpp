/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 *
 * https://leetcode-cn.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (48.75%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 32.7K
 * Testcase Example:  '[2,2,3,4]'
 *
 * 给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
 *
 * 示例 1:
 *
 *
 * 输入: [2,2,3,4]
 * 输出: 3
 * 解释:
 * 有效的组合是:
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 *
 *
 * 注意:
 *
 *
 * 数组长度不超过1000。
 * 数组里整数的范围为 [0, 1000]。
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // 可行，但是超时！
  int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] + nums[j] > nums[k]) {
            cnt++;
          } else {
            break;
          }
        }
      }
    }
    return cnt;
  }

  // 使用二分查找优化k
  int triangleNumber2(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        // 二分查找最大的k
        int left = j + 1, right = n - 1, mid;
        while (left <= right) {
          mid = (right + left) >> 1;
          if (nums[i] + nums[j] > nums[mid]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
        cnt += left - (j + 1);
      }
    }
    return cnt;
  }
};
// @lc code=end
