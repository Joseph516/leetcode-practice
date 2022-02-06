/*
实现 pow(x, n) ，即计算 x 的 n
次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2^-2 = 1/2^2 = 1/4 = 0.25
 

提示：

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
 

注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
 public:
  double myPow(double x, int n) {
    unsigned int abs_n = (unsigned int)n; // 负数转化成绝对值

    double res = myPowDfs(x, abs_n);

    return (n >= 0) ? res : 1 / res;
  }

  // 使用依次相乘会超时
  double myPowDfs(double x, unsigned int n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return x;
    }
    // 可替换成n % 2 == 0
    if (n & 1 == 0) {
      double tmp = myPowDfs(x, n >> 1);
      return tmp * tmp;
    } else {
      double tmp = myPowDfs(x, (n - 1) >> 1);
      return x * tmp * tmp;
    }
  }

  // 迭代版本
  double myPowIter(double x, long n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return x;
    }

    double res = 1;
    while (n != 0) {
      // 可替换成n % 2 == 1
      if (n & 1) {
        res *= x;
      }
      x *= x;
      n >>= 1;
    }
    return res;
  }
};