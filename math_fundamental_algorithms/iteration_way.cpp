#include <cmath>
#include <iostream>

using namespace std;

// 迭代法
class IterationWay {
 public:
  /**
   * @description: 计算整数平方根
   * @param {type} n- 待计算整数，maxTry- 最大计算次数，thresh- 阈值
   * @return: float-平方根，-1- 输入数不大于1，-2- 当前次数及阈值下无法计算。
   */
  float getSquareRoot(int n, int maxTry, float thresh) {
    if (n <= 1) {
      return -1;
    }
    float left = 1;
    float right = n;
    for (int i = 0; i < maxTry; i++) {
      float mid = left + (right - left) / 2;
      float square = mid * mid;
      if (abs(square / n - 1) < thresh) {
        return mid;
      } else if (square > n) {
        right = mid;
      } else {
        left = mid;
      }
    }

    return -2;
  }
};

// test
int main(void) {
  IterationWay test;
  int num = 200;
  float res;
  res = test.getSquareRoot(num, 20, 0.01);
  cout << res << endl;
}
