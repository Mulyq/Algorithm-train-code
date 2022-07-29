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
const int N = 60;
char a[N][N];

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    bool ok = 0;
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < m;j ++) {
            cin >> a[i][j];
            if(a[i][j] == 'B') {
                ok = 1;
            }
        }
    }
    if(!ok) {
        cout << -1 <<'\n';
        return;
    }
    r--,c--;
    if(a[r][c] == 'B') {
        cout << 0 << '\n';
    }
    else {
        bool f = 0;
        for(int i = 0;i < n;i ++) {
            if(a[i][c] == 'B') {
                f = 1;
            }
        }
        for(int i = 0;i < m;i ++) {
            if(a[r][i] == 'B') {
                f = 1;
            }
        }
        if(f) {
            cout << 1 << '\n';
        }
        else cout << 2 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while( T--) {
        solve();
    }
    return 0;
}