/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 *
 * https://leetcode-cn.com/problems/brick-wall/description/
 *
 * algorithms
 * Medium (40.19%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    38.6K
 * Total Submissions: 78.2K
 * Testcase Example:  '[[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]'
 *
 * 你的面前有一堵矩形的、由 n
 * 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和应该相等。
 *
 * 你现在要画一条 自顶向下 的、穿过 最少
 * 砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。
 *
 * 给你一个二维数组 wall ，该数组包含这堵墙的相关信息。其中，wall[i]
 * 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线
 * 穿过的砖块数量最少 ，并且返回 穿过的砖块数量 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：wall = [[1],[1],[1]]
 * 输出：3
 *
 *
 *
 * 提示：
 *
 *
 * n == wall.length
 * 1
 * 1
 * 1
 * 对于每一行 i ，sum(wall[i]) 应当是相同的
 * 1
 *
 *
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  // 该方法无法处理[[100000000,100000000],[100000000,100000000]]，会超时
  int leastBricks(vector<vector<int>>& wall) {
    int n = wall.size();
    int max_num = 0;  // 每行最多的数字个数
    for (int i = 0; i < n; i++) {
      if (wall[i].size() > max_num) {
        max_num = wall[i].size();
      }
    }
    if (max_num == 1) {
      return n;
    }

    // 用cross矩阵记录每行的空行，m块砖中间最短m-1个空
    int** cross = new int*[n];
    int m = 0;
    for (auto v : wall[0]) {
      m += v;
    }
    for (int i = 0; i < n; i++) {
      cross[i] = new int[m - 1]();  // 0表示墙，1表示空
    }
    for (int i = 0; i < n; i++) {
      int ind = -1;
      for (int j = 0; j < wall[i].size() - 1; j++) {
        ind += wall[i][j];
        cross[i][ind] = 1;
      }
    }

    // 找到空最多的一列
    int max_bricks = 0;
    for (int i = 0; i < m - 1; i++) {
      int col_bricks = 0;
      for (int j = 0; j < n; j++) {
        col_bricks += cross[j][i];
      }
      if (col_bricks > max_bricks) {
        max_bricks = col_bricks;
      }
    }
    // 释放
    for (int i = 0; i < n; i++) {
      delete[] cross[i];
    }
    return n - max_bricks;
  }

  // 使用哈希map优化时间复杂度
  int leastBricks2(vector<vector<int>>& wall) {
    int n = wall.size();
    // 用cross矩阵记录每列的空行数目，m块砖中间最短m-1个空
    unordered_map<int, int> cross;
    for (const auto& row : wall) {
      int m = row.size();
      int ind = -1;
      for (int j = 0; j < m - 1; j++) {
        ind += row[j];
        cross[ind]++;  // 0表示墙，1表示空
      }
    }

    // 找到空最多的一列
    int max_bricks = 0;
    for (const auto& col_nums : cross) {
      if (col_nums.second > max_bricks) {
        max_bricks = col_nums.second;
      }
    }
    return n - max_bricks;
  }
};
// @lc code=end
