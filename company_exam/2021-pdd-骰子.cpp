/*
多多君拼团购买了N个骰子，为了方便后面进行活动，多多君需要将这些骰子进行分类。

两个骰子为同类的定义是：
将其中一个骰子通过若干次上下、左右或前后翻转后，其与另一个骰子对应的6面数字均相等。

现在多多君想知道不同种类的骰子的数量分别有多少。

输入描述:
第一行1个整数N，表示骰子的数量。
（1 <= N <= 1,000）
接下来N行，每行6个数字（1～6，且各不相同）
其中第i行表示第i个骰子当前上、下、左、右、前、后这6面的数字。

输出描述:
共2行:
第一行1个整数M，表示不同种类的骰子的个数
第二行M个整数，由大到小排序，表示每个种类的骰子的数量

输入例子1:
2
1 2 3 4 5 6
1 2 6 5 3 4

输出例子1:
1
2

例子说明1:
第二个骰子相当于是第一个骰子从左向右旋转了一面得到，属于同类。

输入例子2:
3
1 2 3 4 5 6
1 2 6 5 3 4
1 2 3 4 6 5

输出例子2:
2
2 1

例子说明2:
第三个骰子无法通过任何旋转变换成第一个或第二个骰子。

输入例子3:
10
2 5 1 3 4 6
5 4 3 2 1 6
1 4 6 2 3 5
1 5 6 3 4 2
6 4 2 1 5 3
3 6 4 5 2 1
1 6 3 4 2 5
5 1 4 2 6 3
6 2 3 1 5 4
5 3 6 1 4 2

输出例子3:
9
2 1 1 1 1 1 1 1 1

例子说明3:
只有第4个骰子(1 5 6 3 4 2)与第8个骰子(5 1 4 2 6 3)属于同一类。

一种可能的变换方式:
1) 首先从右向左翻转1次
 (1 5 6 3 4 2) -> (1 5 4 2 3 6)
2) 然后从上向下翻转2次
 (1 5 4 2 3 6) -> (6 3 4 2 1 5) -> (5 1 4 2 6 3)
*/

#include <vector>
#include <iostream>
using namespace std;

void right(vector<int>&a) {
    swap(a[0], a[3]);
    swap(a[1], a[2]);
    swap(a[0], a[1]);
}

void up(vector<int>&a) {
    swap(a[0], a[5]);
    swap(a[1], a[4]);
    swap(a[0], a[1]);
}

void turn(vector<int>&a) {
    swap(a[2], a[4]);
    swap(a[3], a[5]);
    swap(a[2], a[3]);
}

bool isSimilar(vector<int>&a, vector<int>&b) {
    // 将a和b全部调整到1在最上方
    int cnt = 0;
    while(a[0] != 1 && cnt < 3) {
        right(a);
        cnt++;
    }
    cnt = 0;
    while(a[0] != 1 && cnt < 3) {
        up(a);
        cnt++;
    }
    cnt = 0;
    while(b[0] != 1 && cnt < 3) {
        right(b);
        cnt++;
    }
    cnt = 0;
    while(b[0] != 1 && cnt < 3) {
        up(b);
        cnt++;
    }
    if (a[1] != b[1]) return false;

    // 再判断左右前后
    cnt = 0;
    while(a[2] != b[2] && cnt < 3) {
        turn(b);
        cnt++;
    }
    bool res = true;
    for (int i = 2; i < 6; i++) {
        res &= a[i] == b[i];
    }
    
    return res;
}

int main() {
    int n;
    while(cin >> n) {
        vector<vector<int>> sz(n, vector<int>(6));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> sz[i][j];
            }
        }
        vector<bool> vis(n, false);
        vector<int> ans; 
        int cnt;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            cnt = 1;
            for (int j = i+1; j < n; j++) {
                if (vis[j]) continue;
                if (isSimilar(sz[i], sz[j])) {
                    cnt++;
                    vis[j] = true;
                }
            }
            ans.push_back(cnt);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}