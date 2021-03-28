#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 组合
// 思想：从一些对象n中选出一部分m(1<=m<=n)，不考虑顺序，可能的形式有几种。
// 应用：队伍参赛排序。自然语言处理中，处理输入词。当输入词相同仅顺序不一致时，
// 可以采用组合的概念将其排序，并认定为意思相同。
template<typename T> class Combination {
  private:
  const int firstPrize;
  const int secondPrize;
  const int thirdPrize;

  public:
  Combination(int x, int y, int z)
      : firstPrize(x), secondPrize(y), thirdPrize(z) {
  }
  /**
  * @description:
  * 从10个人中选出三等奖3人，二等奖2人，一等奖1人，不能重复获奖。
  * @param {type} rewardNum- 指定赏金数， result- 奖赏方式结果。
  * @return: null
  */
  void rewardMethods(vector<T> result, vector<T> candidate) {
    unsigned int len = thirdPrize + secondPrize + firstPrize;
    if (result.size() == len) {
      // 输出结果
      resultOutput(result);
      return;
    } else {
      for (unsigned int i = 0; i < candidate.size(); i++) {
        vector<int> resultNew = result;
        resultNew.push_back(candidate[i]);

        vector<int> candidateNew;
        copyElem(candidate, candidateNew, i + 1);
        rewardMethods(resultNew, candidateNew);
      }
    }
  }
  // 数据复制函数
  void copyElem(vector<T>& input, vector<T>& output, int i) {
    vector<int>::iterator it = input.begin() + i;
    for (; it < input.end(); it++) {
      output.push_back(*it);
    }
  }
  // 输出结果
  void resultOutput(vector<T> res) {
    for (unsigned int i = 0; i < res.size(); i++) {
      if (i == thirdPrize) cout << '*';
      if (i == thirdPrize + secondPrize) cout << '*';
      cout << res[i] << ' ';
    }
    cout << endl;
  }
};

// test
int main(void) {
  Combination <int> test(1, 2, 3);
  vector<int> res;
  vector<int> candidate;
  // 输入
  for (unsigned int i = 0; i < 10; i++) {
    candidate.push_back(i + 1);
  }
  test.rewardMethods(res, candidate);
}
