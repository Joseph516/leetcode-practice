// 动态规划问题

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DynamicProgramming {
  private:
  vector<int> money = {1, 2, 3, 7};  // 纸币种类
  vector<int> amountMethod = {0};

  public:
  /**
     * Description: 对于金额固定，找出最少钱币数及方式。
     * prams: amountMoney- 输入总金额
     * return: 
     */
  int findFewerstMethod(int amountMoney) {
    int c[amountMoney];
    int temp[4];
    c[0] = 0;
    c[1] = 1;

    for (unsigned int i = 2; i < amountMoney; i++) {
      for (unsigned int j = 0; j < money.size(); j++) {
        int diff = i - money[j];
        if (0 <= diff) {
          temp[j] = c[diff] + 1;
        } else {
          // 表示该纸币无效，选择某较大值。
          temp[j] = amountMoney;
        }
      }
      // 求出最小值
      int tempMin = temp[0];
      for (int i = 1; i < 4; i++) {
        if (temp[i] < tempMin) {
          tempMin = temp[i];
        }
      }
      c[i] = tempMin;
    }

    return c[amountMoney-1];
  }
};

// test
int main(void) {
  DynamicProgramming test;
  int res = test.findFewerstMethod(100);
  cout << res << endl;

  return 0;
}
