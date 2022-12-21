#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
struct Edge {
    int to, xl, cl;
};
vector<vector<Edge>> G;
vector<bool> vis;
vector<int> h;
void dfs(int x, int hh) {
    vis[x] = 1;
    h[x] = hh;
    for(Edge &y : G[x]) {
        if(vis[y.to]) continue;
        if(hh & 1) y.cl = 1;
        else y.cl = -1;
        dfs(y.to, hh + 1);
    }
}
void solve() {
    cin >> n >> m;
    G.resize(n);
    vis.resize(n);
    h.resize(n);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        G[u].push_back({v, i, 0});
        G[v].push_back({u, i, 0});
    }
    dfs(0, 1);
    vector<int> res(m);
    for(int i = 0; i < n; i ++) {
        for(Edge it : G[i]) {
            if(it.cl == 1) res[it.xl] = 1;
            else if(it.cl == -1) res[it.xl] = 0;
            else {
                if(h[i] == h[it.to]) {
                    if(h[i] & 1) res[it.xl] = 0;
                    else res[it.xl] = 1;
                } else {
                    if(h[i] & 1) res[it.xl] = 1;
                    else res[it.xl] = 0;
                }
                // res[it.xl] = -1;
            }
        }
    }
    for(int v : res) {
        cout << v;
    }
    cout << '\n';
    for(int i  = 0; i < n; i ++ ) G[i].clear();
    vis.clear();
    h.clear();
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