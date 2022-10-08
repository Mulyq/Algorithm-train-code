#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
ll dp[1010][1010];
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> c(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        cnt += ( c[i] = ( a[i] ^ b[i] ) );
    }
    if(cnt & 1) cout << "-1\n";
    else {
        if(y <= x) {
            if(cnt > 2 || cnt == 0) {
                cout << 1ll * cnt / 2 * y << '\n';
            } else {
                bool ok = 0;
                for(int i = 0; i < n - 1; i ++) {
                    if(c[i] == 1 && c[i + 1] == 1) {
                        ok = 1;
                        break;
                    }
                }
                if(!ok) cout << y << '\n';
                else cout << min(2ll * y, 1ll * x) << '\n';
            }
        } else {
            vector<int> pos(1, 0);
            for(int i = 1; i <= n; i ++) {
                if(c[i - 1]) pos.push_back(i);
            }
            n = pos.size() - 1;
            for(int i = 0; i <= n; i ++) {
                for(int j = 0; j <= n; j ++) {
                    dp[i][j] = 1e18;
                }
            }
            for(int i = 0; i < n; i ++) {
                dp[i + 1][i] = 0;
            }
            for(int len = 2; len <= n; len += 2) {
                for(int l = 1; ; l ++) {
                    int r = l + len - 1;
                    if(r > n) break;
                    ll t1 = (pos[l] != pos[r] ? 1ll * y : 1e18), t2 = 1ll * (pos[r] - pos[l]) * x;
                    ll x1 = dp[l + 1][r - 1] + min(t1, t2);
                    t1 = (pos[l] != pos[l + 1] ? 1ll * y : 1e18), t2 = 1ll * (pos[l + 1] - pos[l]) * x;
                    ll x2 = dp[l + 2][r] + min(t1, t2);
                    t1 = (pos[r] != pos[r - 1] ? 1ll * y : 1e18), t2 = 1ll * (pos[r] - pos[r - 1]) * x;
                    ll x3 = dp[l][r - 2] + min(t1, t2);
                    dp[l][r] = min({x1, x2, x3});
                    // cout << l << ' ' << r << ' ' << dp[l][r] << '\n';
                }
            }
            cout << dp[1][n] << '\n';
        }

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