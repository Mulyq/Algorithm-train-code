#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct PAIR {
    int l, r;
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
    vector<array<ll, 3>> dp(n);
    dp[1][2] = 1e18;
    if(p[0].bad || p[1].bad) {
        dp[1][1] = 2ll * (p[1].l - p[0].r);
    }
    for(int i = 2; i < n; i ++) {
        if(p[i].bad) {
            if(p[i - 1].bad) {
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
                dp[i][1] = dp[i - 1][0] + 2ll * (p[1].l - p[0].r);
                if(p[i - 2].bad) {
                    dp[i][2] = dp[i - 1][1] + 2ll * (p[1].l - p[0].r);
                } else {
                    dp[i][2] = 1e18;
                }
            } else {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = dp[i][0] + 2ll * (p[1].l - p[0].r);
                dp[i][2] = 1e18;
            }
        } else {
            if(p[i - 1].bad) {
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
                dp[i][1] = dp[i - 1][0] + 2ll * (p[1].l - p[0].r);
            } else {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = 1e18;
            }
            dp[i][2] = 1e18;
        }
    }
    ll add = min(dp[n - 1][1], dp[n - 1][2]);
    if(!p[n - 1].bad) add = min(add, dp[n - 1][0]);
    res += add;
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
}