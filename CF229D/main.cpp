#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, mod = 998244353, MAXN = 1e5 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = a[i];
    }
    for(int i = 1; i <= n; i ++) {
        s[i] += s[i - 1];
    }
    vector<int> dp(n + 1), last(n + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            if(s[i] - s[j] >= last[j] && dp[i] <= dp[j] + 1) {
                dp[i] = dp[j] + 1, last[i] = s[i] - s[j];
            }
        }
    }
    cout << n - dp[n] << '\n';
}
signed main () {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}