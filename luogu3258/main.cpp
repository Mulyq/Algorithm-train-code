#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 3e5+ 10, mod = 998244353;
int n;
vector<int> e[MAXN];
int a[MAXN], dep[MAXN],fa[MAXN], hson[MAXN], siz[MAXN], top[MAXN], dfn[MAXN], tim;
void dfs1(int r, int f) {
    fa[r] = f;
    siz[r] = 1;
    dep[r] = dep[f] + 1;
    hson[r] = - 1;
    int maxsonsize = 0;
    for(auto v : e[r]) if(v != f) {
        dfs1(v, r);
        siz[r] += siz[v];
        if(maxsonsize < siz[v]) {
            maxsonsize = siz[v];
            hson[r] = v;
        }
    }
}
void dfs2(int r, int topf) {
    top[r] = topf;
    dfn[r] = ++ tim;
    if(hson[r] == - 1) return ;
    dfs2(hson[r], topf);
    for(auto v : e[r]) if(v != fa[r] && v != hson[r]) {
        dfs2(v, v);
    }
}
int d[MAXN << 2], v[MAXN << 2];
void add(int k, int l, int r, int s, int t) {
    if(l == s && r == t) {
        v[k] += 1;
        return ;
    }
    d[k] += (t - s + 1);
    int m = l + r >> 1;
    if(m >= t) {
        add(k << 1, l, m, s, t);
    } else if(s >= m + 1) {
        add(k << 1 | 1, m + 1, r , s, t);
    } else {
        add(k << 1, l, m, s, m);
        add(k << 1 | 1, m + 1, r, m + 1, t);
    }
}

int ask(int k, int l, int r, int s, int t, int z) {
    z += v[k];
    if(l == s && r == t) {
        return d[k] + (t - s + 1) * z;
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t, z);
    } else if(s >= m + 1) {
        return ask(k << 1 | 1, m + 1, r, s, t, z);
    } else {
        return ask(k << 1, l, m, s, m, z) + ask(k << 1 | 1, m + 1, r, m + 1, t, z);
    }
}

void add(int x, int y) {
    if(top[x] == top[y]) {
        if(dep[x] > dep[y]) swap(x, y);
        add(1, 1, n, dfn[x], dfn[y]);
    } else {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        add(1, 1, n, dfn[top[x]], dfn[x]);
        add(fa[top[x]], y);
    }
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(a[0], a[0]);
    dfs2(a[0], a[0]);
    // for(int i = 1; i <= n; i ++) {
    //     cout << top[i] << '\n';
    // }
    vector<int> res(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int l = a[i], r = a[i + 1];
        // cout << l << ' ' << r << '\n';
        add(l, r);
        res[l] --;
        // for(int i = 1; i <= n; i ++) {
        //     cout << res[i] + ask(1, 1, n, dfn[i], dfn[i], 0) << ' ';
        // }
        // cout << '\n';
    }
    res[a[0]] ++;
    res[a[n - 1]] --;
    for(int i = 1; i <= n; i ++) {
        res[i] += ask(1, 1, n, dfn[i], dfn[i], 0);
        cout << res[i] << '\n';
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