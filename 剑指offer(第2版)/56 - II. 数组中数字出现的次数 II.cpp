/*
在一个数组 nums
中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。


示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1
 

限制：

1 <= nums.length <= 10000
1 <= nums[i] < 2^31

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  // 转化成二进制统计每一位出现的次数
  // 其它方法：map
  int singleNumber(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    const int len = 8 * sizeof(int);
    vector<int> cnt_bits(len, 0);
    for (auto & v: nums) {
        cntBits(cnt_bits, v);
    }
    // 统计
    int ans = 0;
    unsigned int interval = 1;
    for(int i = 0; i <= cnt_bits.size()-1; i++) {
        ans += (cnt_bits[i] % 3) * interval;
        interval *= 2;
    }
    return ans;
  }

  void cntBits(vector<int>& cnt_bits, int val) {
      int indx = 0;
      while(val != 0) {
          cnt_bits[indx] += val & 1;
          indx++;
          val >>= 1;
      } 
  }
};