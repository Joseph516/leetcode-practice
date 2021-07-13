/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (35.20%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    67.9K
 * Total Submissions: 174.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 *
 *
 * 示例 2：
 *
 * 输入：c = 3
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：c = 4
 * 输出：true
 *
 *
 * 示例 4：
 *
 * 输入：c = 2
 * 输出：true
 *
 *
 * 示例 5：
 *
 * 输入：c = 1
 * 输出：true
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= c <= 2^31 - 1
 *
 *
 */

// @lc code=start
#include <cmath>

class Solution {
 public:
  // 不易用二分法求解
  bool judgeSquareSum(int c) {
    long left = 0, right = (int)sqrt(c);  // 开方是关键
    while (left <= right) {
      long res = left * left + right * right;
      if (res == c) {
        return true;
      } else if (res > c) {
        right--;
      } else {
        left++;
      }
    }
    return false;
  }
};
// @lc code=end
