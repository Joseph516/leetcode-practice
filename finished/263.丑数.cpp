/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 *
 * https://leetcode-cn.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (50.08%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    74.2K
 * Total Submissions: 145.2K
 * Testcase Example:  '6'
 *
 * 给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回
 * false 。
 *
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 6
 * 输出：true
 * 解释：6 = 2 × 3
 *
 * 示例 2：
 *
 *
 * 输入：n = 8
 * 输出：true
 * 解释：8 = 2 × 2 × 2
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 14
 * 输出：false
 * 解释：14 不是丑数，因为它包含了另外一个质因数 7 。
 *
 *
 * 示例 4：
 *
 *
 * 输入：n = 1
 * 输出：true
 * 解释：1 通常被视为丑数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * -2^31
 *
 *
 */

// @lc code=start
#include <vector>

// 负数都是丑数
class Solution {
 public:
  std::vector<int> candidate{2, 3, 5};
  // 递归方法
  bool isUgly(int n) {
    if (n == 1) {
      return true;
    }
    if (n <= 0) {
      return false;
    }
    decltype(candidate.size()) i;
    for (i = 0; i != candidate.size(); i++) {
      if (n % candidate[i] == 0) {
        n /= candidate[i];
        break;
      }
    }
    return i == candidate.size() ? false : isUgly(n);
  }

  // 用循环代替递归
  bool isUgly_v2(int n) {
    if (n == 1) {
      return true;
    }
    if (n <= 0) {
      return false;
    }
    while (n > 1) {
      if (n % candidate[0] == 0) {
        n /= candidate[0];
      } else if (n % candidate[1] == 0) {
        n /= candidate[1];
      } else if (n % candidate[2] == 0) {
        n /= candidate[2];
      } else {
        // 除不断
        return false;
      }
    }
    return true;
  }

  // 思想精简版本
  bool isUgly_v3(int n) {
    if (n <= 0) {
      return false;
    }
    for (const auto& v : candidate) {
      while (n % v == 0) {
        n /= v;
      }
    }
    return n == 1;
  }
};
// @lc code=end
