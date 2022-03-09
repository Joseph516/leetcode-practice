/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 =
6）的时候卖出，最大利润 = 6-1 = 5 。 注意利润不能是 7-1 = 6,
因为卖出价格需要大于买入价格。 示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

限制：

0 <= 数组长度 <= 10^5

 

注意：本题与主站 121
题相同：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<int> min_val(prices.size(), 0);  // 记录前面的最小值
    int min_prev = prices[0];
    for (size_t i = 1; i < prices.size(); i++) {
      min_val[i] = min_prev;
      if (prices[i] < min_prev) {
        min_prev = prices[i];
      }
    }
    vector<int> dp(prices.size(), 0);
    int max_val = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] >= prices[i - 1]) {
        dp[i] = dp[i - 1] + (prices[i] - prices[i - 1]);
      } else if (prices[i] > min_val[i]) {
        dp[i] = prices[i] - min_val[i];
      } else {
        dp[i] = 0;
      }
      if (dp[i] > max_val) {
        max_val = dp[i];
      }
    }
    return max_val;
  }

  // 优化，用两个数代替动态规划数组
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<int> min_val(prices.size(), 0);  // 记录前面的最小值
    int min_prev = prices[0];
    for (size_t i = 1; i < prices.size(); i++) {
      min_val[i] = min_prev;
      if (prices[i] < min_prev) {
        min_prev = prices[i];
      }
    }

    int dp_prev = 0, dp_cur = 0;
    int max_val = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] >= prices[i - 1]) {
        dp_cur = dp_prev + (prices[i] - prices[i - 1]);
      } else if (prices[i] > min_val[i]) {
        dp_cur = prices[i] - min_val[i];
      } else {
        dp_cur = 0;
      }
      if (dp_cur > max_val) {
        max_val = dp_cur;
      }
      dp_prev = dp_cur;
    }
    return max_val;
  }
};