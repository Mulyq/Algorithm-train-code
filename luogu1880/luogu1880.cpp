#include<bits/stdc++.h>
using namespace std;
int a[210], s[210];
int dp[420][420];
int main () {
    int n;
    cin>> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int i = 1; i <= 2 * n; i ++) {
        s[i] = s[i - 1] + a[i];
    }
    for(int l = 1; l <= n; l ++) {
        for(int i = 1; i <= 2 * n -l; i ++) {
            int j = i + l;
            int all = 1e8;
            for(int x = i; x < j; x ++) {
                all = min(all, dp[i][x] + dp[x + 1][j] + s[j] - s[i - 1]);
            }
            dp[i][j] = all;
        }
    }
    int res = 1e9;
    for(int i = 1; i < n; i ++) {
        res = min(res, dp[i][i + n - 1]);
    }
    cout << res << '\n';
    memset(dp, 0, sizeof dp);
    for(int l = 1; l <= n; l ++) {
        for(int i = 1; i <= 2 * n - l; i ++) {
            int j = i + l;
            int all = -1e8;
            for(int x = i; x < j; x ++) {
                all = max(dp[i][x] + dp[x + 1][j] + s[j] - s[i - 1], all);
            }
            dp[i][j] = all;
            // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    res = -1e9;
    for(int i = 1; i < n; i ++) {
        res = max(res, dp[i][i + n - 1]);
    }
    cout << res << '\n';
}