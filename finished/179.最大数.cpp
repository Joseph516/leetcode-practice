/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (38.11%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    78.3K
 * Total Submissions: 197.2K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数
 * nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 *
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,2]
 * 输出："210"
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出："1"
 *
 *
 * 示例 4：
 *
 *
 * 输入：nums = [10]
 * 输出："10"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(const int& a, const int& b) {
  string ab = to_string(a) + to_string(b);
  string ba = to_string(b) + to_string(a);
  // return ab > ba;
  for (string::size_type i = 0; i < ab.size(); i++) {
    if (ab[i] != ba[i]) {
      return ab[i] > ba[i];
    }
  }
  return false; // 返回true，会出错
}

class Solution {
 public:
  // 提前将数字全部转化成string，可以减少时间。
  string largestNumber(vector<int>& nums) {
    // 排序
    sort(nums.begin(), nums.end(), cmp);
    // 针对输入的都是0的情况
    if (nums[0] == 0) {
      return string("0");
    }

    string res;
    for (const auto& v : nums) {
      res += to_string(v);
    }
    return res;
  }
};

// int main() {
//   vector<int> nums{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//   Solution demo;
//   string res = demo.largestNumber(nums);
// }
// @lc code=end
