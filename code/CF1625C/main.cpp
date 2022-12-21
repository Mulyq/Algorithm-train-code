#include<bits/stdc++.h>

using namespace std;
void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n + 1), d(n + 2);
    for(int i = 1; i <= n; i ++) cin >> d[i]; d[n + 1] = l;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    vector<vector<int>> dp(n + 2,vector<int>(n + 1, 0x3f3f3f3f));
    dp[1][0] = 0;
    for(int i = 2; i <= n + 1; i ++) {
        for(int j = 1; j < i; j ++) {
            for(int x = 1; x <= j; x ++) {
                dp[i][x] = min(dp[i][x], dp[j][x - 1] + a[j] * (d[i] - d[j]));
            }
        }
    }
    int res = 1e9;
    for(int i = n; i >= n - k; i --) {
        res = min(res, dp[n + 1][i]);
    }
    cout << res;
}
int main () {
    int T = 1;
    while(T--) {
        solve();
    }
}