/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  // 贪心算法
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return -1;
    int max_sum = nums[0];
    int cur_sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      cur_sum += nums[i];
      
      // 判断是否从i重新累加
      if (cur_sum <= nums[i]) {
        cur_sum = nums[i];
      }

      if (cur_sum > max_sum) {
        max_sum = cur_sum;
      }
    }
    return max_sum;
  }
};