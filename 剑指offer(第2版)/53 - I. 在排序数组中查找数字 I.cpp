/*
统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
 

注意：本题与主站 34
题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;
class Solution {
 public:
  // 思路：先二分再统计
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
      mid = left + ((right - left) >> 1);
      if (nums[mid] == target) {
        break;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (nums[mid] != target) return 0;

    // 统计
    int cnt = 1;
    for (int i = mid + 1; i < nums.size(); i++) {
      if (nums[i] != target) break;
      cnt++;
    }
    for (int i = mid - 1; i >= 0; i--) {
      if (nums[i] != target) break;
      cnt++;
    }
    return cnt;
  }

  // 优化：直接查找第一个target和最后一个target的位置
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return 0;

    // 第一个target
    int left = 0, right = nums.size() - 1, mid;
    int first = -1;
    while (left <= right) {
      mid = left + ((right - left) >> 1);
      if (nums[mid] == target) {
        // 关键
        if (mid == left || (mid > left && nums[mid - 1] != target)) {
          first = mid;
          break;
        } else {
          right = mid - 1;
        }
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    // 最后一个target
    left = 0, right = nums.size() - 1;
    int last = -1;
    while (left <= right) {
      mid = left + ((right - left) >> 1);
      if (nums[mid] == target) {
        // 关键
        if (mid == right || (mid < right && nums[mid + 1] != target)) {
          last = mid;
          break;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (first != -1 && last != -1) {
      return last - first + 1;
    }
    return 0;
  }
};