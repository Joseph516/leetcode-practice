/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

注意：本题与主站 239
题相同：https://leetcode-cn.com/problems/sliding-window-maximum/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty() || nums.size() < k) return vector<int>{};
    if (k == 1) return nums;

    vector<int> ans;
    deque<int> dq;  // 关键，队首保存滑动窗口的最大值
    dq.push_back(nums[0]);
    int cnt = 1;  // 滑动窗口内数字个数
    for (int i = 1; i < nums.size(); i++) {
      if (cnt < k) {
        if (dq.front() < nums[i]) {
          while (!dq.empty() && dq.front() < nums[i]) {
            dq.pop_front();
          }
        } else {
          while (!dq.empty() && dq.back() < nums[i]) {
            dq.pop_back();
          }
        }
        dq.push_back(nums[i]);
        cnt++;
      }

      if (cnt == k) {
        ans.push_back(dq.front());
        // 队首元素此时离开滑动窗口
        if (nums[i - k + 1] == dq.front()) {
          dq.pop_front();
        }
        cnt--;
      }
    }

    return ans;
  }
};