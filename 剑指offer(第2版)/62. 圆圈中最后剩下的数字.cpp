/*
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

示例 1：
输入: n = 5, m = 3
输出: 3

示例 2：
输入: n = 10, m = 17
输出: 2

限制：

1 <= n <= 10^5
1 <= m <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  // 超时
  int lastRemaining(int n, int m) {
    vector<bool> is_del(n, false);
    int cnt = n, cntm = 0;
    int i = 0, indx;
    while (cnt != 0) {
      if (!is_del[i]) {
        cntm++;
      }
      if (cntm == m) {
        is_del[i] = true;
        cntm = 0;
        cnt--;
      }
      i = (i + 1) % n;
    }
    return (i - 1 + n) % n;
  }

  // 超时， 仍然超时。
  int lastRemaining(int n, int m) {
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      nums[i] = i;
    }
    int cnt = n;
    int i = 0;
    while (cnt != 0 && nums.size() != 1) {
      i = (i + m - 1) % nums.size();
      nums.erase(nums.begin() + i);
      cnt--;
      i = i % nums.size();
    }
    return nums[0];
  }

  int lastRemaining(int n, int m) {
    int last = 0;
    for (int i = 2; i <= n; i++) {
      last = (last + m) % i;
    }
    return last;
  }
};