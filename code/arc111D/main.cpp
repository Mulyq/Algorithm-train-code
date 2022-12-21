#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
struct Edge {
    int u, v;
};
struct edge {
    int to, xl;
};
vector<vector<edge>> e;
vector<Edge> G;
vector<int> res, c;
vector<bool> vis;
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(int i = 0; i < e[u].size(); i ++) {
        int v = e[u][i].to;
        int xl = e[u][i].xl;
        if(G[xl].v == v) {
            res[xl] = -1;
        } else {
            res[xl] = 1;
        }
        dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    G.resize(m);
    res.resize(m), c.resize(n), e.resize(n), vis.resize(n);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        G[i] = {u, v};
    }
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    for(int i = 0; i < m; i ++) {
        auto &[u, v] = G[i];
        if(c[u] > c[v]) {
            res[i] = -1;
        } else if(c[u] < c[v]) {
            res[i] = 1;
        } else {
            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }
    }
    for(int i = 0; i < n; i ++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    for(int i : res) {
        if(i == 1) {
            cout << "<-\n";
        } else {
            cout << "->\n";
        }
    }
}