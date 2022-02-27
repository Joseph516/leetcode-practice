/*
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> permutation(string s) {
    int n = s.size();
    // 可以优化的地方：判断前面是否已经出现过相同元素，从而可以去除ans_set
    set<string> ans_set;
    permutationDfs("", s, ans_set);

    vector<string> ans;
    for (const auto& v : ans_set) {
      ans.push_back(v);
    }
    return ans;
  }

  // 递归方法：将字符串拆分成前半部分和后半部分
  void permutationDfs(string prev, string rest, set<string>& ans_set) {
    if (rest.empty()) {
      return;
    }

    if (rest.size() == 1) {
      ans_set.insert(prev + rest);
    }

    for (size_t i = 0; i < rest.size(); i++) {
      string rest_new = rest.substr(0, i) + rest.substr(i + 1, rest.size());
      permutationDfs(prev + rest[i], rest_new, ans_set);
    }
  }

  // 优化：用交换代替生成子串
  void permutationDfs(string s, size_t idx, set<string>& ans_set) {
    if (idx == s.size()) {
      ans_set.insert(s);
    }

    for (size_t i = idx; i < s.size(); i++) {
      swap(s[i], s[idx]);
      permutationDfs(s, idx + 1, ans_set);
      swap(s[i], s[idx]);
    }
  }

  // 拓展：若求组合
  // 可以不用set，结果是一样的
  vector<string> combine(string s) {
    int n = s.size();
    vector<string> ans;
    for (size_t m = 1; m <= s.size(); m++) {
      combineDfs("", s, m, ans);
    }

    return ans;
  }

  // 从n个字符中选m个字符组合
  void combineDfs(string prev, string rest, size_t m, vector<string>& ans) {
    if (m == 0) {
      ans.push_back(prev);
      return;
    }

    if (rest.empty()) return;

    string rest_new = rest.substr(1, rest.size());

    // 若组合包括第一个字符
    combineDfs(prev + rest[0], rest_new, m - 1, ans);

    // 若组合不包括第一个字符
    combineDfs(prev, rest_new, m, ans);
  }
};

int main() {
  Solution solution;
  string s = "aba";
  vector<string> ans = solution.combine(s);
  for (auto& v : ans) {
    cout << v << " ";
  }
  cout << "\n";
}