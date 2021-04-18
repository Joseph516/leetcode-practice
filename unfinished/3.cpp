#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    int res = 0;
    vector<int> time(n + 1, 0);
    // int time[101];
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> time[i];
    }
    //贪心，每次选最大的两个
    //先排序;
    // sort(time.begin(),time.end());
    for (int i = n - 1; i > 0; --i) {
      res += time[i];  //两者间比较大的
      --i;
      if (i == 1) res += time[0];
    }
    cout << res << endl;
  }
  return 0;
}