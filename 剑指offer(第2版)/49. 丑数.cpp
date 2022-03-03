/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第
n 个丑数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。
注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chou-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;
class Solution {
 public:
  int nthUglyNumber(int n) {
    // 把每个丑数都算出来
    vector<int> ugly_arr(n + 1, 0);
    ugly_arr[1] = 1;
    int index[3] = {1, 1, 1};
    int cand[3] = {2, 3, 5};
    
    for (int i = 2; i <= n; i++) {
      int tmp = min(ugly_arr[index[0]] * 2, ugly_arr[index[1]] * 3);
      ugly_arr[i] = min(tmp, ugly_arr[index[2]] * 5);
      // 更新位置
      for (int j = 0; j < 3; j++) {
        if (ugly_arr[index[j]] * cand[j] <= ugly_arr[i]) {
          index[j]++;
        }
      }
    }
    return ugly_arr[n];
  }
};
