#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while(cin >> str) {
        long long cnt = 0;
        for (int i = 2; i < str.size(); i++) {
            int val;
            if (str[i] <= '9') {
                val = str[i] - '0';
            } else {
                val = str[i] - 'a' + 10;
            }
            while(val) {
                cnt += val & 1;
                val = val >> 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}