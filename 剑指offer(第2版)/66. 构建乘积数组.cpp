/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A
中除了下标 i 以外的元素的积,
即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 

提示：

所有元素乘积之和不会溢出 32 位整数
a.length <= 100000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    if (a.empty()) return vector<int>{};
    vector<int> b(a.size());
    // 计算i左边的值相乘保存在b
    b[0] = 1;
    for (int i = 1; i < a.size(); i++) {
      b[i] = b[i - 1] * a[i - 1];
    }
    // 计算i右边的值相乘保存在right_mul
    int right_mul = 1;
    for (int i = a.size() - 2; i >= 0; i--) {
      right_mul *= a[i + 1];
      b[i] *= right_mul;
    }
    return b;
  }
};