#include<iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    while(cin >> n >> m >> k) {
        vector<vector<int>>a(n, vector<int>(k+1));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0];
            for (int j = 1; j <= a[i][0]; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>>b(m, vector<int>(k+1));
        for (int i = 0; i < m; i++) {
            cin >> b[i][0];
            for (int j = 1; j <= b[i][0]; j++) {
                cin >> b[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            bool flag;
            for (int j = 0; j < n; j++) {
                if (b[i][0] > a[j][0]) {
                    break;
                }
                flag = true;
                for (int kk = 1; kk <= b[i][0]-1; kk++) {
                    if (b[i][kk+1]-b[i][kk] != a[j][kk+1]-a[j][kk]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
}