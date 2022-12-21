#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n;
vector<int> P, Q, S;
unordered_map<PII, ll> dp;
int dfs(int x, int y) {
    if (x > n && y > n)return 1;
    if (dp.count({ x,y }))return dp[{x, y}];
    int ans = 0;
    if (P[x] == S[x + y - 1] && x  <= n) {
        ans += dfs(x + 1, y);
        ans %= mod;
    }
    if (Q[y] == S[x + y - 1] && y <= n) {
        ans += dfs(x, y + 1);
        ans %= mod;
    }
    return dp[{x, y}] = ans;
}
void solve() {
    cin >> n;
    dp.clear();
    P.resize(n + 1), Q.resize(n + 1), S.resize(2 * n + 1);
    for (int i = 1; i <= n; i++)cin >> P[i];
    for (int i = 1; i <= n; i++)cin >> Q[i];
    for (int i = 1; i <= 2 * n; i++)cin >> S[i];
    cout << dfs(1, 1) << '\n';
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