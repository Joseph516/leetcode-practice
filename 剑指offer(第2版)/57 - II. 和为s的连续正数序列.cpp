/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  // 解法同上一题
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> ans;
    int left = 1, right = 2;
    deque<int> cur = {1, 2};
    while (!cur.empty()) {
      int sum = (right + left) * (right - left + 1) / 2;
      if (sum < target) {
        right++;
        cur.push_back(right);
      } else if (sum > target) {
        left++;
        cur.pop_front();
      } else {
        if (cur.size() > 1) {
          ans.push_back(vector<int>(cur.begin(), cur.end()));
        }
        right++;
        cur.push_back(right);
      }
    }
    return ans;
  }
};