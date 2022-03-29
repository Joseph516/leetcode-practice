/*
时间限制：C/C++ 1秒，其他语言2秒

空间限制：C/C++ 256M，其他语言512M

小Q在进行一场竞技游戏,这场游戏的胜负关键就在于能否能争夺一条长度为L的河道,即可以看作是[0,L]的一条数轴。
这款竞技游戏当中有n个可以提供视野的道具−真视守卫,第i个真视守卫能够覆盖区间[xi,yi]。现在小Q想知道至少用几个真视守卫就可以覆盖整段河道。

输入描述:
输入包括n+1行。

第一行包括两个正整数n和L(1<=n<=105,1<=L<=109)

接下来的n行,每行两个正整数xi,yi(0<=xi<=yi<=109),表示第i个真视守卫覆盖的区间。


输出描述:
一个整数，表示最少需要的真视守卫数量, 如果无解, 输出-1。

输入例子1:
4 6
3 6
2 4
0 2
4 7

输出例子1:
3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, l;
  while (cin >> n >> l) {
    vector<vector<long long>> scopes(n, vector<long long>(2));
    for (size_t i = 0; i < n; i++) {
      cin >> scopes[i][0] >> scopes[i][1];
    }
    // 排序
    sort(scopes.begin(), scopes.end(),
         [](const vector<long long>& lhs, const vector<long long>& rhs) {
           if (lhs[0] == rhs[0]) {
             return lhs[1] < rhs[1];
           }
           return lhs[0] < rhs[0];
         });
    long long sl = 0, sr = 0;  // 左右范围
    if (scopes[0][0] != 0) {
      cout << -1 << endl;
      continue;
    }
    // 放置
    long long cnt = 1;
    size_t i = 0;
    while (i < scopes.size() && sr < l) {
      if (scopes[i][0] <= sl) {
        sr = max(scopes[i][1], sr);
        // sr = scopes[i][1]; // 下一个数第一值较大，但是第二个值较小
      } else {
        if (scopes[i][0] <= sr && scopes[i][1] > sr) {
          cnt++;
          sl = sr;
          sr = scopes[i][1];
        }
      }
      i++;
    }
    if (sr < l) {
      cout << -1 << endl;
    } else {
      cout << cnt << endl;
    }
  }
}