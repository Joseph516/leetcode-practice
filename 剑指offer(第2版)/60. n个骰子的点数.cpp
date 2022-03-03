/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n
个骰子所能掷出的点数集合中第 i 小的那个的概率。

 

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:

输入: 2
输出:
[0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
 

限制：

1 <= n <= 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  // 动态规划
  // f(n, s) = f(n-1, s-1)*1/6 + f(n-2, s-2)*1/6 + ... + f(n-1, s-6)*1/6
  vector<double> dicesProbability(int n) {
    vector<double> ans;
    vector<vector<double>> f(n + 1, vector<double>(n * 6 + 1));
    for (int i = 1; i <= 6; i++) {
      f[1][i] = 1.0 / 6;
    }

    for (int i = 2; i <= n; i++) {
      for (int j = i; j <= 6 * i; j++) {
        f[i][j] = 0;
        for (int k = 1; k <= 6; k++) {
          if (j < k + 1) break;
          f[i][j] += f[i - 1][j - k] / 6.0;
        }
      }
    }

    ans.assign(f[n].begin() + n, f[n].begin() + 6 * n + 1);

    return ans;
  }
};
