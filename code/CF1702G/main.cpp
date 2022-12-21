#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 10;
int dep[MAXN], fa[MAXN][20], n, m, q;
vector<int> e[MAXN];
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    for(int v : e[u]) if(v != p) {
        dfs(v, u);
    }
}
void init() {
    dfs(1, 0);
    for(int i = 1; i <= 18; i ++) {
        for(int j = 1; j <= n; j ++) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }
}
int lca(int u, int v) {
    if(dep[u] < dep[v]) {
        swap(u, v);
    }
    int temp = dep[u] - dep[v];
    for(int i = 0; temp; temp >>= 1, i ++) {
        if(temp & 1) {  
            u = fa[u][i];
        }
    }
    if(u == v) return u;
    for(int i = 18; i >= 0; i --) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}
int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    init();
    cin >> q;
    while(q --) {
        int m;
        cin >> m;
        vector<int> p(m);
        for(int i = 0; i < m; i ++) {
            cin >> p[i];
        }
        int lp = 0, rp = 0;
        bool ok = 1;
        for(int i = 0; i < m; i ++) {
            int u = p[i];
            if(lp == 0) {
                lp = u;
            } else if(rp == 0) {
                rp = u;
            } else {
                if(dis(lp, rp) == dis(lp, u) + dis(rp, u)) {
                    continue;
                } else if(dis(lp, u) == dis(lp, rp) + dis(u, rp)) {
                    rp = u;
                } else if(dis(rp, u) == dis(lp, rp) + dis(u, lp)) {
                    lp = u;
                } else {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}