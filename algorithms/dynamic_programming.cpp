// 动态规划问题

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DynamicProgramming {
 private:
  vector<int> money = {1, 2, 3, 7};  // 纸币种类

 public:
  /**
   * Description: 对于金额固定，找出最少钱币数及方式。
   * prams: amountMoney- 输入总金额
   * return: 所需最小纸币数
   */
  int findFewerstMethod(int amountMoney) {
    int c[amountMoney];
    c[0] = 0;

    int temp;
    for (unsigned int i = 1; i < amountMoney; i++) {
      // 用最大值初始化
      int tempMin = amountMoney;
      for (unsigned int j = 0; j < money.size(); j++) {
        int diff = i - money[j];
        if (0 <= diff) {
          temp = c[diff] + 1;
        } else {
          // 此情况表示该纸币无效，选择最大值。
          temp = amountMoney;
        }
        // 求出最小值
        if (temp < tempMin) {
          tempMin = temp;
        }
      }
      c[i] = tempMin;
    }

    return c[amountMoney - 1];
  }
};

// test
int main(void) {
  DynamicProgramming test;
  int res = test.findFewerstMethod(100);
  cout << res << endl;

  return 0;
}
