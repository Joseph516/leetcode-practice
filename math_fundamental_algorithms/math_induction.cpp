#include <cmath>
#include <iostream>

using namespace std;

// 数学归纳法
// 思想：1.证明基本情况（通常n=1）成立;2.假设n=k-1成立，证明
// n=k成立。
// 作用：归纳规律，从而减少推导，节省时间与资源。
class MathInduction {
  private:
  unsigned long wheatNum = 0;       // 当前格麦粒数
  unsigned long wheatTotalNum = 0;  // 当前总共麦粒数

  public:
  /**
   * @description: 用递归&数学归纳法证明舍汗王赏麦总数=2^k - 1
   * @param {type} k- 棋格数
   * @return: 
   */
  bool wheatProve(int k) {
    // 证明n=1成立
    if (k == 1) {
      // n = 1显然成立，不用证明。
      wheatNum = 1;
      wheatTotalNum = 1;
      return true;
    } else {
      // 假设n=k-1成立
      bool flagProvePrev = wheatProve(k - 1);

      // 证明n=k成立
      wheatNum *= 2;
      wheatTotalNum += wheatNum;
      bool flagProve;
      if (wheatTotalNum == (pow(2, k) - 1)) {
        flagProve = true;
      } else {
        flagProve = false;
      }

      // 相等则成立
      if (flagProve && flagProvePrev) {
        return true;
      } else {
        return false;
      }
    }
  }
  /**
   * Desciption: 获取麦粒总数
   */
  long getWheatNum(void) {
    return wheatTotalNum;
  }
};

// test
int main(void) {
  MathInduction test;
  bool res = test.wheatProve(63);
  cout << res << endl;
  // 输出麦粒总数
  cout << test.getWheatNum() << endl;
}
