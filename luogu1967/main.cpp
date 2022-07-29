#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m, q;
vector<array<int, 3>> e;
struct DSU {
    int N;
    vector<int> pr;
    DSU(int n) : N(n) {
        pr.resize(N);
        for(int i = 0; i < n; i ++) {
            pr[i] = i;
        }
    }
    int root(int x) {
        return x == pr[x] ? x : pr[x] = root(pr[x]);
    }
    bool check(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[X] = Y;
        return 0;
    }
} dsu(MAXN);

vector<int> re[MAXN];
int val[MAXN];

int nn;
void kruskal() {
    sort(e.begin(), e.end());
    for(auto [z, x, y] : e) {
        int X = dsu.root(x), Y = dsu.root(y);
        if(X != Y) {
            dsu.unite(X, nn);
            dsu.unite(Y, nn);
            val[nn] = - z;
            re[nn].push_back(X);
            re[nn].push_back(Y);
            // cout << X << ' ' << Y << ' ' << nn << ' ' << - z << '\n';
            nn ++;
        }
    }
}

namespace LCA {
    int fa[MAXN][30], dep[MAXN];
    void dfs(int u, int p) {
        dep[u] = dep[p] + 1;
        fa[u][0] = p;
        for(int v : re[u]) if(v != p) {
            dfs(v, u);
        }
    }
    void init(int r) {
        for(int i = r; i >= 0; i --) {
            if(fa[i][0] == 0) dfs(i, i);
        }
        for(int i = 1; i <= 27; i ++) {
            for(int j = 0; j < nn; j ++) {
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
        for(int i = 27; i >= 0; i --) {
            if(fa[u][i] != fa[v][i]) {
                u = fa[u][i], v = fa[v][i];
            }
        }
        return fa[u][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    nn = n;
    e.resize(m);
    for(auto &[z, x, y] : e) {
        cin >> x >> y >> z;
        x --, y --;
        z = - z;
    }
    kruskal();
    LCA::init(nn - 1);
    cin >> q;
    while(q --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if(dsu.check(x, y)) {
            // cout << LCA::lca(x, y) << '\n';
            cout << val[LCA::lca(x, y)] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}