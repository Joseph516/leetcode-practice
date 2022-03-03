/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"

限制：

1 <= k < s.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;
class Solution {
 public:
  // 思路：双指针
  string reverseLeftWords(string s, int n) {
    int left = 0;
    string sc(s);
    while (left < s.size()) {
      int indx = (left - n + s.size()) % s.size();
      sc[indx] = s[left];
      left++;
    }
    return sc;
  }

  // 思路：两次反转
  string reverseLeftWords(string s, int n) {
    // 反转前半部分
    reserve(s, 0, n - 1);
    // 反转后半部分
    reserve(s, n, s.size() - 1);
    // 反正全部
    reserve(s, 0, s.size() - 1);
    return s;
  }
  void reserve(string& s, int left, int right) {
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};