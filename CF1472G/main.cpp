#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
vector<vector<int>> G;
vector<int> d, dp;
void bfs() {
    queue<PII> q;
    q.push({0, 0});
    d[0] = 0;
    while(q.size()) {
        int u = q.front().first, dis = q.front().second;
        q.pop();
        for(int v : G[u]) {
            if(d[v] == - 1) {
                d[v] = dis + 1;
                q.push({v, d[v]});
            }
        }
    }
}
int dfs (int u) {
    dp[u] = d[u];
    for(int v : G[u]) {
        if(d[v] > d[u]) {
            if(dp[v] <= d[v]) {
                dp[u] = min(dp[u], dp[v]);
            } else {
                dp[u] = min(dp[u], dfs(v));
            }
        } else {
            dp[u] = min(dp[u], d[v]);
        }
    }
    return dp[u];
}
void solve() {
    cin >> n >> m;
    G.resize(n);
    d.resize(n, - 1), dp.resize(n, INF);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        G[u].push_back(v);
    }
    bfs();
    // for(int i = 0; i < n; i ++) {
    //     cout << d[i] << ' ';
    // }
    // cout << '\n';
    dfs(0);
    for(int i = 0; i < n; i ++) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
    d.clear();
    dp.clear();
    for(int i = 0; i < n; i ++) {
        G[i].clear();
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