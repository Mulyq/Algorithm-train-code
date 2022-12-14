#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define int ll
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
         cin >> a[i];
    }
    vector<vector<int>> dp2(n + 2, vector<int> (n + 2)), dp1(n + 2, vector<int> (n + 2));
    for(int i = 0; i <= n; i ++) {
        dp1[i + 1][i] = 1;
    }
    for(int len = 2; len <= n; len += 2) {
        for(int l = 1; l <= n; l ++) {
            int r = l + len - 1;
            if(r > n) break;
            if(a[l] == a[r] && a[l] == 0) {
                (dp2[l][r] = dp1[l + 1][r - 1] * m) %= INF;
            } else if(a[l] > 0 && a[r] < 0 && a[l] + a[r] == 0) {
                dp2[l][r] = dp1[l + 1][r - 1];
            } else if((!a[l]  && a[r] < 0) || (!a[r] && a[l] > 0)) {
                dp2[l][r] = dp1[l + 1][r - 1];
            } else {
                dp2[l][r] = 0;
            }
            for(int x = l; x <= r; x ++) {
                (dp1[l][r] += dp1[l][x - 1] * dp2[x][r]) %= INF;
            }
        }
    }
    cout << dp1[1][n] % INF << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}