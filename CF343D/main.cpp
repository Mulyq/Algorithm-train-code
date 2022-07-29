#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, dep[MAXN], siz[MAXN], fa[MAXN], hson[MAXN], top[MAXN], dfn[MAXN], tim;
vector<int> e[MAXN];
void dfs1(int r, int f) {
    fa[r] = f;
    siz[r] = 1;
    dep[r] = dep[f] + 1;
    hson[r] = - 1;
    int maxssonsisz = 0;
    for(int v : e[r]) if(v != f) {
        dfs1(v, r);
        siz[r] += siz[v];
        if(siz[v] > maxssonsisz) {
            maxssonsisz = siz[v];;
            hson[r] = v;
        }
    }
}
void dfs2(int r, int topf) {
    dfn[r] = ++ tim;
    top[r] = topf;
    if(hson[r] == - 1) return ;
    dfs2(hson[r], topf);
    for(int v : e[r]) if(hson[r] != v && v != fa[r]) {
        dfs2(v, v);
    }
}

int v[MAXN << 2], d[MAXN << 2];
void push_down(int k, int l, int r) {
    if(v[k] != -1) {
        int m = l + r >> 1;
        d[k << 1] = v[k] * (m - l + 1);
        d[k << 1 | 1] = v[k] * (r - m);
        v[k << 1] = v[k];
        v[k << 1 | 1] = v[k];
        v[k] = -1;
    }
}
void add(int k, int l, int r, int s, int t, int x) {
    if(l == s && r == t) {
        v[k] = x;
        d[k] = x * (t - s + 1);
        return ;
    }
    if(v[k] != - 1)
        push_down(k, l, r);
    int m = l + r >> 1;
    if(m >= t) {
        add(k << 1, l, m, s, t, x);
    } else if(s >= m + 1) {
        add(k << 1 | 1, m + 1, r, s , t, x);
    } else {
        add(k << 1, l, m, s, m, x);
        add(k << 1 | 1, m + 1, r,  m + 1, t, x);
    }
    d[k] = d[k << 1] + d[k << 1 | 1];
}

int ask(int k, int l, int r, int s, int t) {
    if(l == s && r == t) {
        return d[k];
    }
    if(v[k] != -1)
        push_down(k, l, r);
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t);
    } else if(s >= m + 1) {
        return ask(k << 1 | 1, m + 1, r , s, t);
    } else {
        return ask(k << 1, l, m, s, m) + ask(k << 1 | 1, m + 1, r, m + 1, t);
    }
}
void op1(int x) {
    add(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, 1);
}
void op2(int x) {
    if(top[x] != 1) {
        add(1, 1, n, dfn[top[x]], dfn[x], 0);
        op2(fa[top[x]]);
    } else {
        add(1, 1, n, 1, dfn[x], 0);
    }
}
void solve() {
    cin >> n;
    fill(v, v + (MAXN << 2),- 1);
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for(int i = 1; i <= n; i ++) {
        // cout << i << ' ' << dfn[i] << ' ' << siz[i] << ' '  << top[i] <<  '\n';
    }
    int q;
    cin >> q;
    while(q --) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            op1(x);
            // for(int i = 1; i <= n; i ++) {
            //     cout << ask(1, 1, n, i, i) << ' ';
            // }
            // cout << '\n';
        } else if(op == 2) {
            op2(x);
            // for(int i = 1; i <= n; i ++) {
            //     cout << ask(1, 1, n, dfn[i], dfn[i]) << ' ';
            // }
            // cout << '\n';
        } else {
            cout << ask(1, 1, n, dfn[x], dfn[x]) << '\n';
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