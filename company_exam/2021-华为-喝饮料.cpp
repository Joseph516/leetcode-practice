/**
 * 买一瓶饮料得一个瓶盖，3个瓶盖可以换一瓶饮料。那买n瓶饮料，最多可以喝多少瓶饮料？
 */

#include <iostream>
#include <vector>

using namespace std;

int Bottle(int n) {
  int cnt = n;
  while(n >= 3) {
    n = n - 3 + 1;
    cnt++;
  }
  if (n == 2) {
    cnt++; // 借一瓶水，喝了兑换之后再换回去？有点扯！！！
  }
  return cnt;
}

int main() {
  for (int i = 0; i <= 10; i++) {
    cout << i << ":" << Bottle(i) << endl;
  }
}