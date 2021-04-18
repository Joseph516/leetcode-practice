/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode-cn.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (41.69%)
 * Likes:    533
 * Dislikes: 0
 * Total Accepted:    55.6K
 * Total Submissions: 133.6K
 * Testcase Example:  '"1 + 1"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "1 + 1"
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
 * s 表示一个有效的表达式
 *
 *
 */

// @lc code=start
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
 private:
  map<char, int> _operator_map;

 public:
  // 操作符优先级，值越小越低。
  void setCompare() {
    _operator_map.insert(pair<char, int>('(', 0));
    _operator_map.insert(pair<char, int>(')', 0));
    _operator_map.insert(pair<char, int>('+', 1));
    _operator_map.insert(pair<char, int>('-', 1));
  }

  bool operatorCompare(const char& a, const char& b) {
    return _operator_map[a] > _operator_map[b];
  }

  bool isOperator(const char& a) {
    int num = a - '0';
    if (num < 0 || num > 9) {
      return true;
    }
    return false;
  }

  int calculate(string s) {
    setCompare();

    stack<char> oprt;  // 操作符栈
    stack<int> opnd;   // 操作数栈
    opnd.push(0);      // 防止第一个数是负数，如"-2+ 1"

    // 特殊情况处理
    string::size_type pos = 0;
    while ((pos = s.find("(+")) != string::npos) {
      s.replace(pos, 2, "(0+");
    }
    while ((pos = s.find("(-")) != string::npos) {
      s.replace(pos, 2, "(0-");
    }

    int res;
    bool start_flag = true;
    while (!oprt.empty() || start_flag) {
      start_flag = false;
      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ' ') {
          continue;
        }
        if (!isOperator(c)) {
          // 数字直接入操作数栈
          // 连续数字可以组合，如"2147483647"是一个数。
          int val = c - '0';
          int j = i + 1;
          while (j < s.size() && !isOperator(s[j])) {
            val = 10 * val + (s[j] - '0');
            j++;
          }
          opnd.push(val);
          i = j - 1;
        } else if (oprt.empty() || c == '(' || operatorCompare(c, oprt.top())) {
          // 如果操作符栈为空或当前操作符优先级更高入栈
          oprt.push(c);
        } else {
          // 当前操作符优先级低，则优先对栈内元素运算
          while (!oprt.empty() && !operatorCompare(c, oprt.top())) {
            char oprt_cur = oprt.top();
            oprt.pop();
            if (oprt_cur == '(') {
              break;
            }
            int opnd_b = opnd.top();
            opnd.pop();
            int opnd_a = opnd.top();
            opnd.pop();
            res = oprt_cur == '+' ? opnd_a + opnd_b : opnd_a - opnd_b;
            opnd.push(res);
          }
          if (c != ')') {
            oprt.push(c);
          }
        }
      }
      // 加判断是针对单个数字的用例
      if (!oprt.empty()) {
        char oprt_cur = oprt.top();
        oprt.pop();
        int opnd_b = opnd.top();
        opnd.pop();
        int opnd_a = opnd.top();
        opnd.pop();
        res = oprt_cur == '+' ? opnd_a + opnd_b : opnd_a - opnd_b;
        opnd.push(res);
      }
    }
    return opnd.top();
  }
};

int main() {
  Solution test;
  std::string s = "1-(+1+1)";
  std::cout << test.calculate(s) << std::endl;
}
// @lc code=end
