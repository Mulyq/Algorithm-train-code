#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, m, q;
vector<tuple<int, int, int>> e; 
struct DSU {
    int N;
    vector<int> pr;
    DSU(int n) : N(n) { 
        pr.resize(N);
        for(int i = 0; i < N; i ++) {
            pr[i] = i;
        }
    }
    int root(int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[X] = Y;
        return 0;
    }
};
vector<int> tre[MAXN << 1];
int val[MAXN << 1];
int nn = n;
void Kruskal() {
    DSU dsu(2 * n + 1);
    sort(e.begin(), e.end());
    for(auto [c, a, b] : e) {
        int x = dsu.root(a), y = dsu.root(b);
        if(x != y) {
            dsu.unite(x, nn);
            dsu.unite(y, nn);
            val[nn] = c;
            tre[nn].push_back(x);
            tre[nn].push_back(y);
            // cout << x << ' '  << y << ' ' << nn << '\n';
            nn ++;
        }
    }
}
int dep[MAXN << 1], fa[MAXN << 1][20];
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    for(int v : tre[u]) if(v != p) {
        dfs(v, u);
    }
}
void init() {
    dfs(nn - 1, nn - 1);
    for(int i = 1; i <= 17; i ++) {
        for(int j = 1; j < nn; j ++) {
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
    for(int i = 17; i >= 0; i --) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}

int d[MAXN << 4];
void build(int k, int l, int r) {
    if(l == r) {
        d[k] = l;
        return ;
    }
    int m = l + r >> 1;
    build(k << 1, l , m), build(k << 1 | 1, m + 1, r);
    d[k] = lca(d[k << 1], d[k << 1 | 1]);
}
int ask(int k , int l, int r, int s, int t) {
    if(l == s && r == t) {
        return d[k];
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t);
    } else if(s >= m + 1) {
        return ask(k << 1 | 1, m + 1, r, s, t);
    } else {
        return lca(ask(k << 1, l, m, s, m), ask(k << 1 | 1, m + 1, r, m + 1, t));
    }
}
void solve() {
    cin >> n >> m >> q;
    nn = n + 1;
    e.resize(m);
    int i = 1;
    for(auto &[c, a, b] : e) {
        cin >> a >> b;
        c = i ++;
    }
    // memset(d, 0, sizeof d);
    for(int i = 1; i <= n * 2; i ++) {
        tre[i].clear();
        dep[i] = 0, 
        memset(fa[i], 0, sizeof fa[i]);
        val[i] = 0;
    }
    Kruskal();
    init();
    build(1, 1, n);
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = i; j <= n; j ++) 
    //     cout << ask(1, 1, n, i, j) << '\n';
    // }
    // cout << '\n';
    while(q --) {
        int l, r;
        cin >> l >> r;
        // cout << ask(1, 1, n, l, r) << '\n';
        cout << val[ask(1, 1, n, l, r)] << ' ';
    }
    cout << '\n';
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