/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (27.61%)
 * Total Accepted:    138.7K
 * Total Submissions: 496.1K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more
 * information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
  string simplifyPath(string path) {
    string res;
    int flag = 0;   // ..
    int flag3 = 0;  // ...
    res.append("/");
    // process
    for (char ch : path) {
      if ((flag == 1) && (ch == '.')) {
        flag3 = 1;
        flag = 0;
      } else if ((flag == 1) && (ch == '/')) {
        res.pop_back();  // .
        res.pop_back();  // .
        if (res.size() > 1) {
          res.pop_back();  // /
          while ((!res.empty()) && (res.back() != '/')) {
            res.pop_back();
          }
        }
        flag = 0;
      }
      if (ch == '/') {
        if (res.back() == '.') {
          // ./
          if (flag3 == 0) {
            res.pop_back();
          }
        } else if (res.back() == '/') {
          // do nothing
        } else {
          res.push_back(ch);
        }
      } else if ((ch == '.') && (res.back() == '.')) {
        // ..
        res.push_back(ch);
        if (flag3 == 0) {
          flag = 1;
        }
      } else {
        res.push_back(ch);
        flag = 0;
      }
    }
    // output
    // 去除一些特殊情况：
    // *..
    if ((flag == 1) && (res.back() == '.')) {
      res.pop_back();
      res.pop_back();
      if (res.size() > 1) {
        res.pop_back();
        while ((!res.empty()) && (res.back() != '/')) {
          res.pop_back();
        }
      }
    }
    // *.
    if ((res.back() == '.') && (flag3 == 0)) {
      res.pop_back();
    }
    // */
    if ((res.size() > 1) && (res.back() == '/')) {
      res.pop_back();
    }
    return res;
  }
};
/*
int main() {
  Solution test;
  string res = test.simplifyPath("/.../");
  cout << res << endl;
}*/
