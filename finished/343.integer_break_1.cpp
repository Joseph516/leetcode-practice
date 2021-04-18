// 整数拆分
// 给定一个整数，输出可以组合的方式。
// 如输入：4 >= 0
// 输出：5
// 5 ：4｜3+1｜2+2｜2+1+1｜1+1+1+1

#include <iostream>
#include <vector>
using namespace std;

int integerBreak(const int &n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  // 初始化
  vector<int> dp(n + 1, 0);  // 动态规划数组，dp[i]表示数字i的组合方式
  vector<vector<int> > dp2(n + 1, vector<int>(n + 1, 0)); // 动态规划数组，dp[i][j]表示数字为i的组合方式中，以数字j开头的组合方式
  dp[0] = dp[1] = 1;
  dp2[1][1] = 1;

  // 依次从小开始动态规划
  for (int i = 2; i <= n; i++) {
    // 对每一个数字从大到小拆分，如n=n+0；n=(n-1)+1...
    for (int j = i; j > 0; j--) {
      int tmp_val = 0;
      int dif = i - j;
      if (dif <= i / 2) {
        tmp_val = dp[dif];
      } else {
        // 后半部分，相当于找和为diff，由j到1开头的组合的个数
        for (int k = j; k >= 1; k--) {
          tmp_val += dp2[dif][k];
        }
      }
      dp2[i][j] = tmp_val;
      dp[i] += tmp_val;
    }
  }
  return dp[n];
}

int main() {
  for (int i = 0; i <= 20; i++) {
    cout << i << ": " << integerBreak(i) << endl;
  }
}