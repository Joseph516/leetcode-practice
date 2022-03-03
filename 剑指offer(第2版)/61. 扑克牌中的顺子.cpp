/*
从若干副扑克牌中随机抽 5
张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为
0 ，可以看成任意数字。A 不能视为 14。

示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True
 

限制：

数组长度为 5 

数组的数取值为 [0, 13] .



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    // 重复数字判断
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1] && nums[i] != 0) {
        return false;
      }
    }

    int cnt0 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        cnt0++;
      } else {
        int idx = nums[i];
        while (i < nums.size()) {
          if (nums[i] == idx) {
            idx++;
            i++;
          } else if (nums[i] != idx && cnt0 > 0) {
            idx++;
            cnt0--;
          } else {
            return false;
          }
        }
        break;
      }
    }
    return true;
  }
};