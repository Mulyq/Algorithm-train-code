#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<vector<int>> G;
vector<int> dep, sz;
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    for(int v : G[u]) if(v != f) {
        dfs(v, u);
    }
}
void dfs2(int u, int f) {
    sz[u] = 1;
    bool ok = 1;
    for(int v : G[u]) if(v != f) {
        dfs2(v, u);
        if(G[v].size() == 1) {
            sz[u] += ok;
            ok = 0;
        } else {
            sz[u] += sz[v];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    G.resize(n);
    dep.resize(n), sz.resize(n);
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        G[u].push_back(v), G[v].push_back(u);
    }
    int mi = 1;
    int mx = 0;
    for(int i = 0; i < n; i ++) {
        if(G[i].size() == 1) {
            dfs(i, i);
            break;
        }
    }
    for(int i = 0; i < n; i ++) {
        if(G[i].size() == 1 && dep[i] % 2 == 0) {
            mi = 3;
            break;
        }
    }
    for(int i = 0; i < n; i ++) {
        if(G[i].size() > 1) {
            dfs2(i, i);
            mx = sz[i] - 1;
            break;
        }
    }
    cout << mi << ' ' << mx << '\n';
}