/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

提示：

s.length <= 40000
注意：本题与主站 3
题相同：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;

    int max_len = 0, cur_len;
    int left = 0, right = 1, i;
    while (left < s.size() && right < s.size()) {
      // 查找是否存在重复字符
      for (i = left; i < right; i++) {
        if (s[right] == s[i]) {
          break;
        }
      }
      if (i == right) {
        right++;
      } else {
        // 存在重复，从left+1开始统计
        cur_len = right - left;
        if (cur_len > max_len) {
          max_len = cur_len;
        }
        left = i + 1;
        cur_len = 0;
      }
    }
    return max_len > right - left ? max_len : right - left;
  }
};