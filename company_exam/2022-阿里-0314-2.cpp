#include <bits/stdc++.h>
using namespace std;

int res = 0;

int main() {
  int m, n;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  vector<vector<int>> f(n, vector<int>(m, 0));
  vector<vector<int>> res_recor(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  //向上的
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f[i][j] = 0;
      if (mat[i][j] == 1 || i == 0) {
        continue;
      }
      if (mat[i - 1][j] == 1) {
        f[i][j] = 1;
      } else {
        f[i][j] = f[i - 1][j];
      }
      res_recor[i][j] += f[i][j];
    }
  }

  //向下的
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      f[i][j] = 0;
      if (mat[i][j] == 1 || i == n - 1) {
        continue;
      }
      if (mat[i + 1][j] == 1) {
        f[i][j] = 1;
      } else {
        f[i][j] = f[i + 1][j];
      }
      res_recor[i][j] += f[i][j];
    }
  }

  //向左的
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      f[i][j] = 0;
      if (mat[i][j] == 1 || j == 0) {
        continue;
      }
      if (mat[i][j - 1] == 1) {
        f[i][j] = 1;
      } else {
        f[i][j] = f[i][j - 1];
      }
      res_recor[i][j] += f[i][j];
    }
  }

  //向右的
  for (int j = m - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      f[i][j] = 0;
      if (mat[i][j] == 1 || j == m - 1) {
        continue;
      }
      if (mat[i][j + 1] == 1) {
        f[i][j] = 1;
      } else {
        f[i][j] = f[i][j + 1];
      }
      res_recor[i][j] += f[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res += res_recor[i][j];
    }
  }
  cout << res << endl;
  return 0;
}