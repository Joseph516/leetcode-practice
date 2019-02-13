/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (44.90%)
 * Total Accepted:    62K
 * Total Submissions: 136.2K
 * Testcase Example:  '[0,0,0,0]'
 *
 * 
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
 * indexed).
 * 
 * Once you pay the cost, you can either climb one or two steps. You need to
 * find minimum cost to reach the top of the floor, and you can either start
 * from the step with index 0, or the step with index 1.
 * 
 * 
 * Example 1:
 * 
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the
 * top.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
 * cost[3].
 * 
 * 
 * 
 * Note:
 * 
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 * 
 * 
 */
class Solution {
  public:
  int minCostClimbingStairs(vector<int>& cost) {
    // dynamic programming-strategy is important
    // function: f[i] = cost[i] + min(f[i+1], f[i+2])
    int len = cost.size();
    int i = len - 1;
    int f0 = 0, f1 = 0, f2 = 0;  // f[i],f[i+1],f[i+2]
    while (i >= 0) {
      f0 = cost[i] + min(f1, f2);
      f2 = f1;
      f1 = f0;
      i--;
    }
    return min(f1, f2);
  }
  int min(int f1, int f2) {
    int temp;
    return temp = f1 < f2 ? f1 : f2;
  }
};
