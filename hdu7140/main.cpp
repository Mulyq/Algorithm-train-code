#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, m;
int v[MAXN], w[MAXN];
bitset<1050> dp[2][1050];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < 1024; i ++) {
        dp[0][i].reset();
    }
    for(int i = 1; i <= n; i ++) {
        cin >> w[i] >> v[i];
    }
    dp[0][0][m] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int k = 0; k < 1024; k ++) {
            dp[1][k] = dp[0][k];
            dp[1][k] >>= w[i];
        }
        for(int j = 0; j < 1024; j ++) {
            dp[0][j] |= dp[1][j ^ v[i]];
        }
    }
    for(int i = 1023; i >= 0; i --) {
        if(dp[0][i][0]) {
            cout << i << '\n';
            return;
        }
    }
    cout << - 1 << '\n';
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