#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll, 2>> dp(n + 1);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    a[0] = a[n];
    ll res = 1e18;
    for(int i = 1; i <= n; i ++) {
        if(i == 1) {
            dp[i][0] = 1e18;
            dp[i][1] = a[1];
        } else {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][0] + a[i - 1]);
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a[i];
        }
    }
    res = min(res, min(dp[n][1], dp[n][0]));
    for(int i = 0; i <= n; i ++) {
        dp[i][0] = dp[i][1] = 0;
    }
    for(int i = 1; i <= n; i ++) {
        if(i == 1) {
            dp[i][1] = 1e18;
        } else {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][0] + a[i - 1]);
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a[i];
        }
    }
    res = min(res, dp[n][1]);
    cout << res << '\n';
}