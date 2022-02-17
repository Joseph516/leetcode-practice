/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

class Solution {
 public:
  // 重点在这几个if，没想好。
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> out;
    if (matrix.empty()) return out;

    int len_row = matrix.size(), len_col = matrix[0].size();
    // start表示对角线位置
    int i = 0, start = 0, end_y = len_row - 1, end_x = len_col - 1;
    while (start <= end_x && start <= end_y) {
      // 从左至右一整行
      for (i = start; i <= end_x; i++) {
        out.push_back(matrix[start][i]);
      }
      // 从上到下
      if (start < end_y) {
        for (i = start + 1; i <= end_y; i++) {
          out.push_back(matrix[i][end_x]);
        }
      }
      // 从右到左
      if (start < end_x && start < end_y) {
        for (i = end_x - 1; i >= start; i--) {
          out.push_back(matrix[end_y][i]);
        }
      }
      // 从下到上
      if (start < end_x && start < end_y - 1) {
        for (i = end_y - 1; i >= start + 1; i--) {
          out.push_back(matrix[i][start]);
        }
      }
      start++;
      end_y--;
      end_x--;
    }
    return out;
  }
};