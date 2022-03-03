/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0

限制：

0 <= n < 2^31
注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <cmath>
#include <string>
using namespace std;

class Solution {
 public:
  int findNthDigit(int n) {
    if (n < 10) return n;
    // 求n处于几位数
    long long add_res = 1;   // 累加和, int会溢出
    long long interval = 9;  // 每个位数的数字个数，1位9，2位90，3位900,...
    int num_digits = 1;      // 位数
    while (add_res < n) {
      add_res += interval * num_digits;
      num_digits++;
      interval *= 10;
    }
    if (add_res == n) {
      return 1;
    }

    // 回到上一位
    num_digits--;
    interval /= 10;
    add_res -= interval * num_digits;
    int diff = n - add_res;

    // n对应完整的num_digits位数的值
    int value = pow(10, num_digits - 1) + diff / num_digits;
    int idx = diff % num_digits;

    return to_string(value)[idx] - '0';
  }
};

int main() {
  Solution s;
  s.findNthDigit(1000);
}