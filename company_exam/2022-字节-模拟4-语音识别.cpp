/*
https://bytedance.feishu.cn/file/boxcn0VhRhQ1TfRPJMdv2L6wWjd
*/

#include <iostream>
#include <map>
#include <vector>

typedef struct Node {
  Node() { cnt = 0; }
  ~Node() {
    for (auto& v : child) {
      delete child[v.first];
    }
  }
  int cnt;  // 重复次数
  std::map<int, Node*> child;
} Node;

void addTrie(Node* cur, const std::vector<int>& arr, int cur_idx) {
  cur->cnt++;
  if (cur_idx == arr[0]) {
    return;
  }
  int leap = arr[cur_idx + 1] - arr[cur_idx];
  if (cur->child.find(leap) == cur->child.end()) {
    cur->child.emplace(std::pair<int, Node*>(leap, new (Node)));
  }
  addTrie(cur->child[leap], arr, cur_idx + 1);
}

int searchTrie(Node* cur, const std::vector<int>& arr, int cur_idx) {
  if (cur_idx == arr[0]) {
    return cur->cnt;
  }
  int leap = arr[cur_idx + 1] - arr[cur_idx];
  if (cur->child.find(leap) == cur->child.end()) {
    return 0;
  }
  return searchTrie(cur->child[leap], arr, cur_idx + 1);
}

// 字典树方法，先对a建立字典树，然后用b搜索。可以减小时间复杂度。
void compareSignalTrie(int n, int m, const std::vector<std::vector<int>>& a,
                       const std::vector<std::vector<int>>& b) {
  // 建立树
  Node* root = new (Node);
  for (const auto& v : a) {
    addTrie(root, v, 1);
  }

  // 搜索树
  for (const auto& v : b) {
    int cnt = searchTrie(root, v, 1);
    std::cout << cnt << std::endl;
  }
}

// 常规暴力搜索
void compareSignal(int n, int m, const std::vector<std::vector<int>>& a,
                   const std::vector<std::vector<int>>& b) {
  // 比较信号量
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (b[i][0] > a[j][0]) {
        continue;
      }
      int ik;
      for (ik = 1; ik <= b[i][0] - 1; ik++) {
        if (b[i][ik + 1] - b[i][ik] != a[j][ik + 1] - a[j][ik]) {
          break;
        }
      }
      // 找到一致信号量
      if (ik == b[i][0]) {
        cnt++;
      }
    }
    std::cout << cnt << std::endl;
  }
}

int main() {
  int n, m, k;
  while (std::cin >> n >> m >> k) {
    // 处理输入
    std::vector<std::vector<int>> a(n, std::vector<int>(k + 1));
    for (int i = 0; i < n; i++) {
      std::cin >> a[i][0];
      for (int j = 1; j <= a[i][0]; j++) {
        std::cin >> a[i][j];
      }
    }
    std::vector<std::vector<int>> b(m, std::vector<int>(k + 1));
    for (int i = 0; i < m; i++) {
      std::cin >> b[i][0];
      for (int j = 1; j <= b[i][0]; j++) {
        std::cin >> b[i][j];
      }
    }

    // compareSignal(n, m, a, b);
    compareSignalTrie(n, m, a, b);
  }
}