#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define int ll
const int MAXN = 2e5 + 10, mod = 998244353;
const ll INF = (1ll << 60);
struct PAIR {
    ll l, r;
    bool bad = 0;
};
void solve() {
    int n;
    cin >> n;
    vector<PII> a(2 * n);
    for(int i = 0; i < 2 * n; i ++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    ll res = 0;
    vector<PAIR> p(n);
    for(int i = 0; i < n; i ++) {
        p[i].l = a[2 * i].first;
        p[i].r = a[2 * i + 1].first;
        res += p[i].r - p[i].l;
        int mx = max(a[2 * i].second, a[2 * i + 1].second);
        int mi = min(a[2 * i].second, a[2 * i + 1].second);
        if(mx - 1 == mi && (mx % 2 == 0)) {
            p[i].bad = 1;
        }
    }
    vector<array<ll, 2>> dp(n);
    dp[0][0] = dp[0][1] = INF;
    dp[0][p[0].bad] = 0;
    for(int i = 1; i < n; i ++) {
        dp[i][0] = dp[i][1] = INF;
        dp[i][p[i].bad] = dp[i - 1][0];
        dp[i][0] = min(dp[i][0], min(dp[i - 1][0], dp[i - 1][1]) + 2 * (p[i].l - p[i - 1].r));
    }
    res += dp[n - 1][0];
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
}