/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3
一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：

用返回一个整数列表来代替打印
n 为正整数


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> printNumbers(int n) {
    int number = 1;
    vector<int> res;
    int dist = 10;
    while (n != 0) {
      res.push_back(number);
      number++;
      if (number / dist != 0) {
        dist *= 10;
        n--;
      }
    }
    return res;
  }

  // 先找到n对应的最大值，再打印
  vector<int> printNumbers2(int n) {
    int max_num = 0;
    for (int i = 0; i < n; i++) {
      max_num *= 10;
      max_num += 9;
    }

    vector<int> res;
    for (int i = 1; i <= max_num; i++) {
      res.push_back(i);
    }
    return res;
  }
};