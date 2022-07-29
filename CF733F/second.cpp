#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m, S;
ll res;
map<int, int> tab;
struct Edge {
    int form, to, w, c, xl;
    bool operator< (const Edge &a) const {
        return w < a.w;
    }
};

struct DSU {
    int N;
    vector<int> pr;
    DSU(int n) : N(n) {
        pr.resize(N + 1);
        for(int i = 0; i <= N; i ++) {
            pr[i] = i;
        }
    }
    int root (int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
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
};

vector<Edge> e;
vector<PII> tre[MAXN];
vector<int> te[MAXN];
void kruskal() {
    DSU dsu(n);
    sort(e.begin(), e.end());
    for(auto [u, v, w, c, xl] : e) {
        if(!dsu.unite(u, v)) {
            res += w;
            tab[xl] = w;
            tre[u].push_back({xl, w});
            tre[v].push_back({xl, w});
        }
    }
}

void ch() {
    for(int i = 1; i <= n; i ++) {
        if(te[i].size() < 2) continue; 
        int v = te[i][0];
        for(int j = 1; j < te[i].size(); j ++) {
            te[v].push_back(te[i][j]);
        }
    }
}

int dfn[MAXN], dep[MAXN], siz[MAXN], fa[MAXN], hson[MAXN], top[MAXN], val[MAXN], rk[MAXN], tim;

int d[MAXN << 2], t[MAXN];

void dfs1(int r, int f) {
    dep[r] = dep[f] + 1;
    siz[r] = 1;
    fa[r] = f;
    hson[r] = -1;
    int maxsonsize = 0;
    for(int v : te[r]) if(v != f) {
        dfs1(v, r);
        siz[r] += siz[v];
        if(siz[v] > maxsonsize) {
            hson[r] = v;
            maxsonsize = siz[v];
        }
    }
}

void dfs2(int r, int topf) {
    dfn[r] = ++ tim;
    t[tim] = val[r];
    rk[tim] = r;
    top[r] = topf;
    if(hson[r] == - 1) return ;
    dfs2(hson[r], topf);
    for(auto v : te[r]) if(v != hson[r] && v != fa[r]) {
        dfs2(v, v);
    }
}

void build(int k, int l, int r) {
    if(l == r) {
        d[k] = val[l];
        return ;
    }
    int m = l + r >> 1;
    build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
    d[k] = max(d[k << 1], d[k << 1 | 1]);
}
PII ask(int k, int l, int r, int s, int t) {
    if(l == s && r == t) {
        return {d[k], l};
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t);
    } else if(s >= m + 1) {
        return ask(k << 1 | 1, m + 1, r, s, t);
    } else {
        return max(ask(k << 1, l, m, s, m), ask(k << 1 | 1, m + 1, r, m + 1, r));
    }
}

PII ask(int l, int r) {
    if(top[l] == top[r]) {
        if(dep[l] > dep[r]) swap(l, r);
        return ask(1, 1, n, dfn[l], dfn[r]);
    } else {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        return max(ask(1, 1, n, dfn[top[l]], dfn[l]), ask(fa[top[l]], r));
    }
}

void solve() {
    cin >> n >> m;
    e.resize(m);
    for(int i = 0; i < m; i ++) {
        cin >> e[i].w;
        e[i].xl = i + 1;
        val[i + 1] = e[i].w;
    }
    for(int i = 0; i < m; i ++) {
        cin >> e[i].c;
    }
    for(int i = 0; i < m; i ++) {
        cin >> e[i].form >> e[i].to;
    }
    cin >> S;
    kruskal();
    dfs1(1, 1);
    dfs2(1, 1);
    ch();
    n --;
    build(1, 1, n);
    ll T = res;
    int up = 0;
    int kk = -1;
    PII ww;
    for(auto [u, v, w, c, xl] : e) {
        w -= S / c;
        PII K = ask(u, v);
        int maxR = K.first, Xl = K.second;
        if(maxR - w > up) {
            kk = Xl;
            up = maxR - w;
            res = T - up;
            ww = {xl, w};
        }
    }
    if(kk != -1) {
        tab.erase(kk);
        tab[ww.first] = ww.second;
    }
    cout << res << '\n';
    for(auto x : tab) {
        cout << x.first << ' ' << x.second << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}