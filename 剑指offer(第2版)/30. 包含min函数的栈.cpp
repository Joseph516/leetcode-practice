/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min
函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();   --> 返回 0.
minStack.min();   --> 返回 -2.

提示：

各函数的调用总次数不超过 20000 次

注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <limits>
#include <stack>
using namespace std;

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    data_.push(x);
    if (data_min_.empty() || x <= data_min_.top()) {
      data_min_.push(x);
    }
  }

  void pop() {
    int x = data_.top();
    data_.pop();
    if (!data_min_.empty() && x == data_min_.top()) {
      data_min_.pop();
    }
  }

  int top() { return data_.top(); }

  int min() { return data_min_.top(); }

 private:
  stack<int> data_;
  stack<int> data_min_;
};

// 存两个数的方法，第一个表示前面的最小值，第二个表示当前的值
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    data_.push(min_);
    data_.push(x);
    if (x < min_) {
      min_ = x;
    }
  }

  void pop() {
    data_.pop();
    min_ = data_.top(); // 该位置为前面的最小值
    data_.pop();
  }

  int top() { return data_.top(); }

  int min() { return min_; }

 private:
  stack<int> data_;
  int min_ = numeric_limits<int>::max();
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */