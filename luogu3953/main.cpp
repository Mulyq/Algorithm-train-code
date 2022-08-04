#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m, k, p;
vector<vector<PII>> G, rG;
vector<vector<ll>> dp;
vector<ll> dis1, dis2;
void init() {
    rG.clear();
    G.clear();
    dp.clear();
    dis1.clear();
    dis2.clear();
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

void Dij2(int s) {
    vector<vector<bool>> vis(n + 1, vector<bool> (k + 1));
    struct node {
        int u, d, len;
        bool operator< (const node &a) const {
            return d > a.d;
        }
    };
    
    priority_queue<node> q;
    q.push({s, 0, 0});
    dp[s][0] = 1;
    while(q.size()) {
        int u = q.top().u, d = q.top().d, len = q.top().len;
        q.pop();
        if(vis[u][d + dis2[u] - dis1[n]]) continue;
        vis[u][d + dis2[u] - dis1[n]] = 1;
        for(auto &[v, w] : G[u]) {
            int ex = d + w + dis2[v] - dis1[n];
            if(ex > k) continue;
            (dp[v][ex] += dp[u][d + dis2[u] - dis1[n]]) %= p;
            q.push({v, d + w, len + 1});
        }
    }
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
    Dij2(1);
    ll res = 0;
    for(int i = 0; i <= k; i ++) {
        (res += dp[n][i]) %= p;
    }
    cout << res % p << '\n';
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