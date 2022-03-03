/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I
am a student. "，则输出"student. a am I"。

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
注意：本题与主站 151
题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/

注意：此题对比原题有改动

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

class Solution {
 public:
  // 优化思路：先反转整个字符，再反转单个字符
  string reverseWords(string s) {
    if (s.empty()) return "";
    string ans;

    int right = s.size() - 1;
    for (int i = s.size() - 2; i >= 0; i--) {
      if (s[i] == ' ' && s[right] == ' ') {
        right--;
      } else if (s[i] == ' ' && s[right] != ' ') {
        ans = ans + s.substr(i + 1, right - i) + " ";
        right = i - 1;
      } else if (s[i] != ' ' && s[right] == ' ') {
        right = i;
      }
    }
    if (right >= 0 && s[right] != ' ') {
      ans += s.substr(0, right + 1);
    } else if (!ans.empty()) {
      ans.pop_back();
    }
    return ans;
  }
};
