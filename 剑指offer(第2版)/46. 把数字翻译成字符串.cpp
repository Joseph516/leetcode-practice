/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成
“b”，……，11 翻译成 “l”，……，25 翻译成
“z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int translateNum(int num) { return translateNumRecur(to_string(num)); }

  // 递归版本
  int translateNumRecur(string num_str) {
    if (num_str.empty()) return 0;
    if (num_str.size() == 1 && num_str[0] <= '9') {
      return 1;
    }

    int cnt = 0;
    // 第一个数字单独翻译
    cnt += translateNumRecur(num_str.substr(1, num_str.size()));
    // 注意不要重复计算次数
    if (num_str.size() == 1) {
      cnt++;
    }

    // 前两个数字结合翻译
    if (num_str.size() > 1 && stoi(num_str.substr(0, 2)) < 26 &&
        num_str[0] != '0') {
      cnt += translateNumRecur(num_str.substr(2, num_str.size()));
      // 注意不要重复计算次数
      if (num_str.size() == 2) {
        cnt++;
      }
    }

    return cnt;
  }

  // 动态规划版本, pass 36/49
  int translateNumDp(string num_str) {
    if (num_str.empty()) return 0;
    if (num_str.size() == 1) return 1;

    bool is_two = false; // 字母是否已经结合成两位数了
    vector<int> dp(num_str.size(), 0);
    dp[0] = 1;
    for (int i = 1; i < num_str.size(); i++) {
      if (stoi(num_str.substr(i - 1, i + 1)) < 26 && num_str[i - 1] != '0' && !is_two) {
        dp[i] = dp[i - 1] + 1;
        is_two = true;
      } else {
        dp[i] = dp[i - 1];
        is_two = false;
      }
    }
    return dp[dp.size() - 1];
  }
};