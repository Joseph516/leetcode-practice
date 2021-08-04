/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 *
 * https://leetcode-cn.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (47.93%)
 * Likes:    380
 * Dislikes: 0
 * Total Accepted:    45.1K
 * Total Submissions: 89.4K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 *
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi,
 * wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 *
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1
 * 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * times[i].length == 3
 * 1 i, vi
 * ui != vi
 * 0 i
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
 *
 *
 */

// @lc code=start
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  // dijkstra
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    const int inf = numeric_limits<int>::max() >> 1;
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (auto& t : times) {
      int x = t[0] - 1, y = t[1] - 1;
      g[x][y] = t[2];
    }
    vector<int> dist(n, inf);
    dist[k - 1] = 0;
    vector<bool> visited(n, false);
    // 这里相对严蔚敏教材中，多一次循环。
    for (int i = 0; i < n; i++) {
      // 找到距离当前点距离最近的点
      int x = -1;
      for (int y = 0; y < n; y++) {
        if (!visited[y] && (x == -1 || dist[y] < dist[x])) {
          x = y;
        }
      }
      // 更新最近点点到其他点的距离
      visited[x] = true;
      for (int y = 0; y < n; y++) {
        dist[y] = min(dist[y], dist[x] + g[x][y]);
      }
    }
    int ans = *max_element(dist.begin(), dist.end());
    return ans == inf ? -1 : ans;
  }
};

// FIXME: 这个方法在处理已访问过点时存在问题。
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> min_time(n, -1);  // 每个节点的最短时间
    min_time[k - 1] = 0;
    vector<bool> visted(n, false);
    // DFS
    networkDelayTimeSearch(times, n, k, min_time, visted);
    // min_time的最大值为网络延迟时间
    int delay = -1;
    for (const auto& mt : min_time) {
      if (mt == -1) {
        return -1;
      }
      if (mt > delay) {
        delay = mt;
      }
    }
    return delay;
  }

  void networkDelayTimeSearch(const vector<vector<int>>& times, const int& n,
                              const int& k, vector<int>& min_time,
                              vector<bool>& visted) {
    visted[k - 1] = true;
    // 寻找邻接点
    vector<int> neighs_indexes;
    findNeighborhoodIndex(times, k, neighs_indexes);
    for (auto& indx : neighs_indexes) {
      int neigh = times[indx][1];
      if (visted[neigh - 1]) {
        continue;
      }
      if (min_time[neigh - 1] == -1) {
        min_time[neigh - 1] = min_time[k - 1] + times[indx][2];
      } else if (min_time[neigh - 1] > min_time[k - 1] + times[indx][2]) {
        min_time[neigh - 1] = min_time[k - 1] + times[indx][2];
      } else {
        // do nothing
      }
      visted[neigh - 1] = true;
      networkDelayTimeSearch(times, n, neigh, min_time, visted);
    }
  }

  // 寻找k的邻接点在times中的index
  void findNeighborhoodIndex(const vector<vector<int>>& times, int k,
                             vector<int>& neighs_indexes) {
    for (vector<vector<int>>::size_type i = 0; i < times.size(); i++) {
      if (times[i][0] == k) {
        neighs_indexes.push_back(i);
      }
    }
  }
};

// @lc code=end
