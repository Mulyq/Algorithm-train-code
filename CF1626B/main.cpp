#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    string s;
    cin >> s;
    int len = s.size();
    for(int i = len - 2;i >= 0;i --) {
        int k = s[i] + s[i + 1] - '0' - '0';
        if(k >= 10) {
            s[i] = k / 10 + '0';
            s[i + 1] = k % 10 + '0';
            for(int j = 0;j < len;j ++) {
                cout << s[j];
            }
            cout << '\n';
            return;
        }
    }
    s[1] = s[0] + s[1] - '0';
    for(int j = 1;j < len;j ++) {
                cout << s[j];
            }
            cout << '\n';
            return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}