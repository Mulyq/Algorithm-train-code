#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m, k, p;
vector<vector<PII>> G, rG, nG;
vector<vector<ll>> dp;
vector<ll> dis1, dis2;
void init() {
    rG.clear();
    G.clear();
    dp.clear();
    dis1.clear();
    dis2.clear();
    nG.clear();
    nG.resize(n + 1);
    rG.resize(n + 1);
    G.resize(n + 1);
    dis1.resize(n + 1, INF);
    dis2.resize(n + 1, INF);
    dp.resize(n + 1, vector<ll> (k + 1));
}
void Dij(int s, int t) {
    vector<bool> vis(n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    dis1[s] = 0;
    while(q.size()) {
        int u = q.top().second, dd = q.top().first;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(PII it : G[u]) {
            int v = it.first, w = it.second;
            if(dis1[v] > dis1[u] + w) {
                dis1[v] = dis1[u] + w;
                q.push({dis1[v], v});
            }
        }
    }
    vis.clear();
    vis.resize(n + 1);
    q.push({0, t});
    dis2[t] = 0;
    while(q.size()) {
        int u = q.top().second, dd = q.top().first;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(PII it : rG[u]) {
            int v = it.first, w = it.second;
            if(dis2[v] > dis2[u] + w) {
                dis2[v] = dis2[u] + w;
                q.push({dis2[v], v});
            }
        }
    }
}
ll dfs(int u, int d) {
    int all = 0;
    int ex = d + dis2[u] - dis1[n];
    if(ex > k) return all;
    if(u == n) {
        all ++;
    }
    if(dp[u][ex]) return dp[u][ex];
    for(auto [v, w] : G[u]) {
        (all += dfs(v, d + w)) %= p;
    }
    return dp[u][ex] = all;
}
void solve() {
    cin >> n >> m >> k >> p;
    init();
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        rG[b].push_back({a, c});
    }
    Dij(1, n);
    vector<int> deg(n + 1);
    queue<int> q;
    for(int i = 1; i <= n; i ++) {
        int u = i;
        for(auto [v, w] : G[u]) {
            if(dis1[u] + w + dis2[v] <= dis1[n] + k && w == 0) {
                nG[u].push_back({v, w});
                deg[v] ++;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(deg[i] == 0) {
            q.push(i);
        }
    }
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto [v, w] : nG[u]) {
            if(--deg[v] == 0) {
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(deg[i]) {
            cout << "-1\n";
            return;
        }
    }
    dfs(1, 0);
    cout << dp[1][0] % p << '\n';
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