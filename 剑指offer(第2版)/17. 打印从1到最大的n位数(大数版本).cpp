#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  // 考虑到n可能很大，需要用字符串表示数字
  vector<string> printNumbers(int n) {
    string number(n, '0');
    vector<string> numbers;

    while (!increment(number)) {
      numbers.push_back(number);
    }

    return numbers;
  }

  // increment不断递增number，并返回是否达到最大值
  bool increment(string& number) {
    bool num_takeover = 0;  // 进位
    int len = number.size();
    for (int i = len - 1; i >= 0; i--) {
      int num_sum = number[i] - '0' + num_takeover;
      // 最低位递增
      if (i == len - 1) {
        num_sum++;
      }
      // 进位判断
      if (num_sum >= 10) {
        if (i == 0) {
          return true;
        } else {
          num_sum -= 10;
          number[i] = '0' + num_sum;
          num_takeover = 1;
        }
      } else {
        number[i] = '0' + num_sum;
        break;
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  if (argc != 2) {
    exit(0);
  }

  int n = atoi(argv[1]);
  Solution s;
  for (const auto& v : s.printNumbers(n)) {
    std::cout << v << std::endl;
  }
}