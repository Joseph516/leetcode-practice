/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 *
 * https://leetcode-cn.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (53.87%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 52.2K
 * Testcase Example:  '1'
 *
 * 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表
 * 分钟（0-59）。每个 LED 代表一个 0 或 1，最低位在右侧。
 *
 *
 * 例如，下面的二进制手表读取 "3:25" 。
 *
 *
 *
 *
 * （图源：WikiMedia - Binary clock samui moon.jpg
 * ，许可协议：Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0) ）
 *
 * 给你一个整数 turnedOn ，表示当前亮着的 LED
 * 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
 *
 * 小时不会以零开头：
 *
 *
 * 例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
 *
 *
 * 分钟必须由两位数组成，可能会以零开头：
 *
 *
 * 例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：turnedOn = 1
 * 输出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：turnedOn = 9
 * 输出：[]
 *
 *
 *
 *
 * 解释：
 *
 *
 * 0
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int hours[10] = {1, 2, 4, 8, 0, 0, 0, 0, 0, 0};
  int mins[10] = {0, 0, 0, 0, 1, 2, 4, 8, 16, 32};
  vector<string> res;

  // 时针和小于11，分针和小于59
  vector<string> readBinaryWatch(int turnedOn) {
    backtracking(turnedOn, 0, 0, 0);
    return res;
  }

  // 回溯法：
  // turnedOn: 剩余未亮的LED数目
  // index: 从该位置开始点亮LED
  // hour: 时针和；min：分针和
  void backtracking(int turnedOn, int index, int hour, int min) {
    if (hour > 11 || min > 59) {
      return;
    }
    if (turnedOn == 0) {
      res.push_back(getTime(hour, min));
    }
    for (int i = index; i < 10; i++) {
      // trick:均增加hours[i]或mins[i]，但实际上每次只有一个能加，
      // 因为hours和mins非0部分不重合。
      // 递归：从i+1位置开始点亮，未亮LED数目减1.
      backtracking(turnedOn - 1, i + 1, hour + hours[i], min + mins[i]);
    }
  }

  string getTime(const int& h, const int& m) {
    string tmp = to_string(h) + ':';
    if (m < 10) {
      tmp += '0' + to_string(m);
    } else {
      tmp += to_string(m);
    }
    return tmp;
  }
};
// @lc code=end
