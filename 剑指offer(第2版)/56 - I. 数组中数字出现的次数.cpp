/*
一个整型数组 nums
里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

 

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：

2 <= nums.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> singleNumbers(vector<int>& nums) {
    // 异或运算
    int res_xor = 0;
    for (auto& v : nums) {
      res_xor ^= v;
    }
    // 找到二进制1的位置
    unsigned int indxBit = 0;
    // 注意这里&运算必须用括号，不然会先计算1==0
    while ((res_xor & 1) == 0 && indxBit < 8 * sizeof(int)) {
      res_xor = res_xor >> 1;
      indxBit++;
    }
    // 分组获得两个不重复的值
    int v1 = 0, v2 = 0;
    for (auto& v : nums) {
      if (isGrop(v, indxBit)) {
        v1 ^= v;
      } else {
        v2 ^= v;
      }
    }
    return vector<int>{v1, v2};
  }

  bool isGrop(int v, unsigned int indxBit) { return (v >> indxBit) & 1; }
};