// 动态规划问题

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DynamicProgramming {
  private:
  vector<int> money = {1, 2, 3, 7}; // 纸币种类
  vector<int> amountMethod = {0};

  public:
  /**
     * Description: 对于金额固定，找出最少钱币数及方式。
     * prams: amountMoney- 输入总金额
     * return: 
     */
  int findFewerstMethod(int amountMoney) {
    if (amountMoney == 0) {
      amountMethod[0] = 0;
    }
    int tempMin = amountMoney;
    int temp;
    for (unsigned int i = 0; i < money.size(); i++) {
      int diff = amountMoney - money[i];
      if (0 <= diff) {
        temp = findFewerstMethod(diff) + 1;
      } else {
        temp = ;
      }
      if (temp < tempMin) {
        tempMin = temp;
      }
    }
    amountMethod[i] = tempMin;
    return amountMethod[i];
  }
};

// test
int main(void) {
  DynamicProgramming test;
  int res = test.findFewerstMethod(50);
  cout << res << endl;

  return 0;
}
