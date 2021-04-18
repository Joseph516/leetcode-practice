#include <bits/stdc++.h>
using namespace std;

bool compare(const std::vector<int> &a, const std::vector<int> &b) {
  return (float)a[0] / a[1] > (float)b[0] / b[1];
}

// 充电过程中也会耗电
float calLastTime(int n, int w, std::vector<std::vector<int>> &battary) {
  sort(battary.begin(), battary.end(), compare);
  battary[0][1] -= w;

  //   a[i] += (w - b[i]) * t;
  return -1;
}

int main() {
  int t, n, w;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> w;
    std::vector<int> a(n, 0), b(n, 0);
    std::vector<std::vector<int>> battary(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      std::cin >> battary[i][0] >> battary[i][1];
    }
    std::cout << calLastTime(n, w, battary) << std::endl;
  }
}