/*
请定义一个队列并实现函数 max_value
得到队列里的最大值，要求函数max_value、push_back 和 pop_front
的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入:
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入:
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <deque>
using namespace std;

class MaxQueue {
 private:
  deque<int> values_;      // 队列的所有值
  deque<int> max_values_;  // 当前队列的最大值

 public:
  MaxQueue() {}

  int max_value() {
    if (max_values_.empty()) return -1;
    return max_values_.front();
  }

  void push_back(int value) {
    while (!max_values_.empty() && value > max_values_.back()) {
      max_values_.pop_back();
    }
    max_values_.push_back(value);
    values_.push_back(value);
  }

  int pop_front() {
    if (values_.empty()) return -1;
    if (values_.front() == max_values_.front()) {
      max_values_.pop_front();
    }
    int ret_val = values_.front();
    values_.pop_front();
    return ret_val;
  }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */