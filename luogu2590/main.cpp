#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 3e4+ 10, mod = 998244353;
int n;
int a[MAXN], dep[MAXN], fa[MAXN], siz[MAXN], dfn[MAXN], hson[MAXN], top[MAXN], tim;
vector<int> e[MAXN];
void dfs1(int r, int f) {
    fa[r] = f;
    dep[r] = dep[f] + 1;
    siz[r] = 1;
    hson[r] = - 1;
    int maxsonsize = 0;
    for(int v : e[r]) if(v != f) {
        dfs1(v, r);
        siz[r] += siz[v];
        if(siz[v] > maxsonsize) {
            maxsonsize = siz[v];
            hson[r] = v;
        }
    }
}
int w[MAXN];
void dfs2(int r, int topf) {
    dfn[r] = ++ tim;
    top[r] = topf;
    w[tim] = a[r];
    if(hson[r] == -1) return ;
    dfs2(hson[r], topf);
    for(int v : e[r]) if(v != fa[r] && v != hson[r]) {
        dfs2(v, v);
    }
}
int d[2][MAXN << 2];
void build(int k, int l, int r) {
    if(l == r) {
        d[0][k] = d[1][k] = w[l];
        return ;
    }
    int m = l + r >> 1;
    build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
    d[0][k] = max(d[0][k << 1], d[0][k << 1 | 1]); 
    d[1][k] = d[1][k << 1] + d[1][k << 1 | 1]; 
}
void ch(int k, int l, int r, int x, int t) {
    if(l == r) {
        d[0][k] = d[1][k] = t;
        return ;
    }
    int m = l + r >> 1;
    if(m >= x) {
        ch(k << 1, l, m, x, t);
    } else {
        ch(k << 1 | 1, m + 1, r, x, t);
    }
    d[0][k] = max(d[0][k << 1], d[0][k << 1 | 1]); 
    d[1][k] = d[1][k << 1] + d[1][k << 1 | 1]; 
}

PII ask(int k, int l, int r, int s, int t) {
    if(l == s && r == t) {
        return {d[0][k], d[1][k]};
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t);
    } else if(s >= m + 1) {
        return ask(k << 1 | 1, m + 1, r , s, t);
    } else {
        PII t1 = ask(k << 1, l, m, s, m), t2 = ask(k << 1 | 1, m + 1, r, m + 1, t);
        return {max(t1.first, t2.first), t1.second + t2.second};
    }
}

PII ask(int l, int r) {
    if(top[l] == top[r]) {
        if(dep[l] > dep[r]) swap(l, r);
        return ask(1, 1, n, dfn[l], dfn[r]);
    } else {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        PII t1 = ask(1, 1, n, dfn[top[l]], dfn[l]);
        PII t2 = ask(fa[top[l]], r);
        return {max(t1.first, t2.first), t1.second + t2.second};
    }
}
void solve() {
    cin >> n;
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    int q;
    cin >> q;
    while(q --) {
        string op;
        cin >> op;
        int x, y;
        if(op == "CHANGE") {
            cin >> x >> y;
            ch(1, 1, n, dfn[x], y);
        } else {
            cin >> x >> y;
            PII res = ask(x, y);
            if(op[1] == 'M') cout << res.first << '\n';
            else cout << res.second << '\n';
        }
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