/*
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6

限制：

1 <= n < 2^31
注意：本题与主站 233
题相同：https://leetcode-cn.com/problems/number-of-digit-one/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <cmath>
#include <string>
using namespace std;

class Solution {
 public:
  // 超时
  int countDigitOne(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      string ns = to_string(i);
      int res = 0;
      for (auto& v : ns) {
        ans += v == '1';
      }
    }
    return ans;
  }

  // 找规律，解答参考《剑指offer2》
  int countDigitOne(int n) {
    string ns = to_string(n);
    return countRecursive(ns);
  }

  int countRecursive(const string& ns) {
    if (ns.empty()) return 0;

    if (ns.size() == 1 && ns[0] == '0') return 0;
    if (ns.size() == 1 && ns[0] > '0') return 1;

    int num_first_digit = 0;
    if (ns[0] > '1') {
      num_first_digit = pow(10, ns.size() - 1);
    } else if (ns[0] == '1') {
      num_first_digit = stoi(ns.substr(1, ns.size())) + 1;
    }

    int num_other = (ns[0] - '0') * (ns.size() - 1) * pow(10, ns.size() - 2);
    int num_recursive = countRecursive(ns.substr(1, ns.size()));

    return num_first_digit + num_other + num_recursive;
  }
};