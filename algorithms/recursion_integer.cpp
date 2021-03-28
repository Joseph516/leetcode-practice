#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**一个整数可以被分解为多个整数的乘积，
 * 例如，6 可以分解为 2x3。求给定整数的所有解。
 */
// 递归法
class Recursion_Integer {
  private:
  //vector<int> integerCandidate = {2, 3, 4, 5, 6, 7, 8, 9};
  int totalSolutionNum = 1;

  public:
  /**
   * @description: 求给定整数的所有解。
   * @param {type} num- 指定数， result- 奖赏方式结果。 
   * @return: 
   */
  void getIntegerSolution(int num, vector<int> result) {
    // 1xnum
    if (result.empty()) {
      cout << "1x" << num << endl;
    }
    if (num == 1) {
      // 输出解答方式
      outputResult(result);
    } else {
      for (int i = 2; i <= num; i++) {
        int mod = num % i;
        if (0 == mod) {
          int q = num / i;
          vector<int> resultTemp = result;
          resultTemp.push_back(i);
          getIntegerSolution(q, resultTemp);
        }
      }
    }
  }
  /**
   * Desciption: 获得解答总数
   */
  int getTotalSolution(void) {
    return totalSolutionNum;
  }

  // 输出结果
  void outputResult(vector<int> res) {
    for (unsigned int i = 0; i < res.size(); i++) {
      cout << res[i] << 'x';
    }
    cout << '1' << endl;
    totalSolutionNum += 1;
  }
};

// test
int main(void) {
  Recursion_Integer test;
  vector<int> res;
  test.getIntegerSolution(20, res);
  // 输出解答方式
  cout << "总的解答方式有：";
  cout << test.getTotalSolution() << "种" << endl;
}
