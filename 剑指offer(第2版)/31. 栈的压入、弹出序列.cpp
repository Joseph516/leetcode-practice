/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列
{1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1}
是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。
注意：本题与主站 946
题相同：https://leetcode-cn.com/problems/validate-stack-sequences/



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if (pushed.empty() && popped.empty()) return true;
    if (pushed.size() != popped.size()) return false;

    stack<int> st;
    int i = 0, j = 0;
    while (i < pushed.size() && j < popped.size()) {
      // pop前表示push前面不等的数全部入栈
      while (i < pushed.size() && j < popped.size() && pushed[i] != popped[j]) {
        st.push(pushed[i]);
        i++;
      }
      i++;
      j++;
      // 相等的数同步出栈
      while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
        j++;
        st.pop();
      }
    }
    return st.empty();
  }
};