#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MANX = 1e3 + 10;
int a[MANX][MANX];
int dp1[MANX][MANX], dp2[MANX][MANX];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            dp1[i][j] = dp2[i][j] = 0;
        }
    }
    if((n + m - 1) % 2 == 1) {
        cout << "NO\n";
        return ;
    }
    for(int i =0; i <= m; i ++) {
        dp1[0][i] = -INF;
        dp2[0][i] = INF;
    }
    for(int i =0; i <= n; i ++) {
        dp1[i][0] = -INF;
        dp2[i][0] = INF;
    }
    dp1[1][1] = dp2[1][1] = a[1][1];
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(i == 1 && j == 1) continue;
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
            dp2[i][j] = a[i][j] + min(dp2[i - 1][j], dp2[i][j - 1]);
        }
    }
    if(dp1[n][m] >= 0 && dp2[n][m] <= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}