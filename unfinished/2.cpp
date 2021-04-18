#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int ans;
  cin >> n;
  string s;
  cin >> s;
  ans = n;
  bool flag = true;
  vector<bool> record(n, false);

  while (flag) {
    flag = false;
    for (int i = 0; i < n - 1; ++i) {
      if (record[i] == true) {
        continue;
      } else {
        int j = i + 1;
        while (j < n && record[j] == true) j++;
        if (j == n) break;
        if (record[i] == false && record[j] == false &&
            (s[i] + s[j] - 2 * '0' == 10)) {
          record[i] = true;
          record[j] = true;
          flag = true;
          ans = ans - 2;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}