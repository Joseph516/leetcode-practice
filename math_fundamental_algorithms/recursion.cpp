#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 递归法
// 思想：数学归纳法的逆运算。将n=k的情况，逐渐缩小用n=1求解。
class Recursion {
  private:
  // 纸币形式
  vector<int> money = {1, 2, 5, 10};
  int totalRewardWay = 0;

  public:
  /**
   * @description: 给定奖赏金额，用递归法求奖赏方式，有1,2,5,10四种纸币。
   * @param {type} rewardNum- 指定赏金数， result- 奖赏方式结果。 
   * @return: 
   */
  void rewardMethods(int rewardNum, vector<int> result) {
    if (rewardNum == 0) {
      // 输出奖励方式
      outputResult(result);

    } else if (rewardNum < 0) {
      return;
    } else {
      for (unsigned int i = 0; i < money.size(); i++) {
        int temp = rewardNum - money[i];
        vector<int> resultTemp = result;
        resultTemp.push_back(money[i]);
        rewardMethods(temp, resultTemp);
      }
    }
  }
  /**
   * Desciption: 奖励方式总数
   */
  int getRewardWays(void) {
    return totalRewardWay;
  }

  // 输出结果
  void outputResult(vector<int> res) {
    for (unsigned int i = 0; i < res.size(); i++) {
      cout << res[i] << ' ';
    }
    cout << endl;
    totalRewardWay += 1;
  }
};

// test
int main(void) {
  Recursion test;
  vector<int> res;
  test.rewardMethods(10, res);
  // 输出奖励方式总数
  cout << "总的奖励方式有：";
  cout << test.getRewardWays() << "种" << endl;
}
