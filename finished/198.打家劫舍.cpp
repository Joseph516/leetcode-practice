/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (48.08%)
 * Likes:    1408
 * Dislikes: 0
 * Total Accepted:    283.3K
 * Total Submissions: 577.5K
 * Testcase Example:  '[1,2,3,1]'
 *
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。z
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下
 * ，一夜之内能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[1,2,3,1]
 * 输出：4
 * 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 2：
 *
 * 输入：[2,7,9,3,1]
 * 输出：12
 * 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋
 * (金额 = 1)。 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  // 动态规划
  int rob(vector<int>& nums) {
    vector<int>::size_type n = nums.size();
    if (n == 0) {
      return 0;
    }
    // 若为了减小内存，可以考虑不用数组，直接用两个数表示dp[i-2]和dp[i-1]
    int dp[n + 1];  // 有1-n个房子时候，小偷投到的最大现金
    dp[0] = 0;
    dp[1] = nums[0];
    // 当有i个房子时，若偷第i房子，则不能偷第i-1房子，现金为nums[i-1]+dp[i-2'
    // 否则为dp[i - 1]
    for (vector<int>::size_type i = 2; i <= n; i++) {
      dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp[n];
  }
};
// @lc code=end
