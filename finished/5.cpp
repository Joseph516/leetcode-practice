#include <math.h>
#include <stdio.h>

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

long long mod = 1000000000;
int f[1009][1009], a[1009];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++) f[i][0] = 1;
  for (int j = 1; j <= m; j++)
    if (j % a[1] == 0) f[1][j] = 1;
  // for (int j = 1; j <= m; j++) f[1][j] = j/a[1];  也可以这样写

  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= j / a[i]; k++)
        f[i][j] += f[i - 1][j - a[i] * k], f[i][j] %= mod;

  printf("%d", f[n][m]);

  return 0;
}
