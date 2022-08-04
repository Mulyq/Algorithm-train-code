#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<vector<PII>> G;
vector<int> dis;
vector<int> dp;
int n, m;
void init() {
    G.clear();
    dis.clear();
    dp.clear();
    dp.resize(n + 1);
    dis.resize(n + 1, INF);
    G.resize(n + 1);
}
void Dij(int s) {
    vector<bool> vis(n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    dis[s] = 0;
    dp[s] = 1;
    while(q.size()) {
        int u = q.top().second, d = q.top().first;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(PII it : G[u]) {
            int v = it.first, w = it.second;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                dp[v] = dp[u];
                q.push({dis[v], v});
            } else if(dis[v] == dis[u] + w) {
                dp[v] += dp[u];
                q.push({dis[v], v});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    for(int i = 0; i < n; i ++) {
        sort(G[i].begin(), G[i].end());
        G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
    }
    Dij(1);
    if(dis[n] == INF) {
        cout << "No answer\n";
    } else {
        cout << dis[n] << ' ' << dp[n] << '\n';
    }
}