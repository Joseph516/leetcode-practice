/*
求 1+2+...+n
，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45
 

限制：

1 <= n <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qiu-12n-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Add {
 private:
  static int sum_;
  static int n_;

 public:
  Add() { n_++, sum_ += n_; }
  ~Add() {}
  static void reset() {n_ = 0; sum_ = 0;}

  static int getSum() { return sum_; }
};

int Add::sum_ = 0;
int Add::n_ = 0;

class Solution {
public:
    int sumNums(int n) {
        Add::reset();
        Add * tmp = new Add[n];
        delete[] tmp;
        tmp = nullptr;
        return Add::getSum();
    }
};

