/**
 * 华为2021.8.25机试题
 * 给定一个迷宫，计算从左上角至右下角的最短步长。注：迷宫中的数值表示时间，没走一步数值减一。
 */

#include <iostream>
#include <vector>
using namespace std;

int N, M;  //分别代表行和列
int steps, path_temp, path_best;
vector<vector<int>> maze;    //迷宫矩阵
vector<vector<int>> visted;  //存储最佳路径

void MazeTrack(int i, int j) {
  visted[i][j] = 1;  //表示当前节点已走，不可再走
  path_temp += 1;    //将当前节点加入到路径中
  steps += 1;

  //判断是否到达终点
  if (i == N - 1 && j == M - 1) {
    if (path_best == -1 || path_temp < path_best) {
      path_best = path_temp;
    }
  }

  //探索向上走是否可行
  if (i - 1 >= 0 && !visted[i - 1][j] && maze[i - 1][j] > steps) {
    MazeTrack(i - 1, j);
  }
  //探索向下走是否可行
  if (i + 1 < N && !visted[i + 1][j] && maze[i + 1][j] > steps) {
    MazeTrack(i + 1, j);
  }
  //探索向左走是否可行
  if (j - 1 >= 0 && !visted[i][j - 1] && maze[i][j - 1] > steps) {
    MazeTrack(i, j - 1);
  }
  //探索向右走是否可行
  if (j + 1 < M && !visted[i][j + 1] && maze[i][j + 1] > steps) {
    MazeTrack(i, j + 1);
  }
  //恢复现场，设为未走
  visted[i][j] = 0;
  steps -= 1;
  path_temp -= 1;
}

int main() {
  while (cin >> N >> M) {
    // 获取输入
    maze = vector<vector<int>>(N, vector<int>(M, 0));
    visted = vector<vector<int>>(N, vector<int>(M, 0));
    path_temp = -1;
    path_best = -1;
    steps = -1;
    for (auto &i : maze) {
      for (auto &j : i) {
        cin >> j;
      }
    }

    if (maze[0][0] <= 0) {
      std::cout << path_best << std::endl;
      continue;
    }

    //回溯寻找迷宫最短通路
    MazeTrack(0, 0);

    // 统计最短时长
    std::cout << path_best << std::endl;
  }
  return 0;
}