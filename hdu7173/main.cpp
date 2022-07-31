#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n;
vector<int> a, b,s;
vector<array<int, 2>> dp;
int dfs(int x, int y, int tag) {
    if(x > n && y > n) {
        return 1;
    }
    if(dp[x + y - 1][tag] != -1) return dp[x + y - 1][tag];
    ll res = 0;
    if(a[x] == s[x + y - 1] && x <= n) {
        res += dfs(x + 1, y, tag);
    }
    if(b[y] == s[x + y - 1] && y <= n) {
        res += dfs(x, y + 1, tag);
    }
    return res = dp[x + y - 1][tag] % mod;
}
void solve() {
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    s.resize(2 * n + 1);
    dp.resize(2 * n + 1, {-1, -1});
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    for(int i = 1; i <= 2 * n; i ++) {
        cin >> s[i];
    }
    cout << ( dfs(1, 1, 0) + dfs(1, 0, 1) )% mod << '\n';
    dp.clear();
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