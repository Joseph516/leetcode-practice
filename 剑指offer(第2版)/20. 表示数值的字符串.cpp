/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
示例 4：

输入：s = "    .1  "
输出：true
 

提示：

1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点
'.' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  bool isNumber(string s) {
    // 清除首尾空格
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    if (s.empty()) return false;
    if (s.size() == 1) return isNumberChar(s[0]);

    size_t pos = 0;
    bool numeric = scanInteger(s, pos);

    // '.'一定出现在'e'的前面
    if (pos != s.size() && s[pos] == '.') {
      numeric = scanUinteger(s, ++pos) || numeric;
    }

    if (pos != s.size() && (s[pos] == 'e' || s[pos] == 'E')) {
      numeric = numeric && scanInteger(s, ++pos);
    }

    return numeric && pos == s.size();
  }

  bool isNumberChar(const char& ss) { return ss >= '0' && ss <= '9'; }

  bool scanInteger(const string& s, size_t& pos) {
    if (s[pos] == '+' || s[pos] == '-') {
      pos++;
    }
    return scanUinteger(s, pos);
  }

  // 扫描若存在数字返回true，否则false，pos记录非数字位置
  bool scanUinteger(const string& s, size_t& pos) {
    bool exist_num = false;
    while (pos != s.size() && isNumberChar(s[pos])) {
      pos++;
      exist_num = ~exist_num;
    }
    return exist_num;
  }
};