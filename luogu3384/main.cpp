#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e5 + 10, mod = 998244353;
int N = 1e5 + 7;

int n, m, p, r;
vector<int> tre[MAXN];
int fa[MAXN], siz[MAXN], hson[MAXN], dfn[MAXN], dep[MAXN], top[MAXN], rnk[MAXN], tim;

ll d[MAXN << 2], v[MAXN << 2], a[MAXN];

// seg tre
void add(int k, int l, int r, int s, int t, int z) {
    if(l == s && r == t) {
        v[k] += z;
        return;
    }
    (d[k] += (t - s + 1) * z) %= p;
    int m = l + r >> 1;
    if(m >= t) {
        add(k << 1, l, m, s, t, z);
    } else if(m < s) {
        add(k << 1 | 1, m + 1, r, s, t, z);
    } else {
        add(k << 1, l, m, s, m, z);
        add(k << 1 | 1, m + 1, r, m + 1, t, z); 
    }
}

ll ask(int k, int l, int r, int s, int t, ll z) {
    z += v[k];
    if(l == s && r == t) {
        return (t - s + 1) * z + d[k] ;
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t, z) ;
    } else if(s > m) {
        return ask(k << 1 | 1, m + 1, r, s, t, z) ;
    } else {
        return ask(k << 1, l, m, s, m, z) +
               ask(k << 1 | 1, m + 1, r, m + 1, t, z) ;
    }
}

// 树链剖分
void dfs1(int r, int f) {
    siz[r] = 1;
    fa[r] = f;
    dep[r] = dep[f] + 1;
    hson[r] = -1;
    int maxsiz = -1;
    for(auto v : tre[r]) if(f != v) {
        dfs1(v, r);
        siz[r] += siz[v];
        if(siz[v] > maxsiz) {
            hson[r] = v;
            maxsiz = siz[v];
        }
    }
}

void dfs2(int r, int topf) {
    dfn[r] = ++ tim;
    rnk[tim] = r;
    add(1, 1, N, tim, tim, a[r]);
    top[r] = topf;
    if(hson[r] == -1) return ;
    dfs2(hson[r], topf);
    for(auto v : tre[r]) if(v != fa[r] && v != hson[r]) {
        dfs2(v, v);
    }
}

// operator 1 2 3 4
void op1(int x, int y, ll z) {
    if(top[x] == top[y]) {
        if(dep[x] > dep[y]) swap(x, y);
        add(1, 1, N, dfn[x], dfn[y], z);
    } else {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        add(1, 1, N, dfn[top[x]], dfn[x], z);
        op1(fa[top[x]], y, z);
    }
}

ll op2(int x, int y) {
    ll res = 0;
    if(top[x] == top[y]) {
        if(dep[x] > dep[y]) swap(x, y);
        (res += ask(1, 1, N, dfn[x], dfn[y], 0)) ;
    } else {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        res += ask(1, 1, N, dfn[top[x]], dfn[x], 0) +
               op2(fa[top[x]], y) ;
    }
    return res % p;
}
void op3(int x, int z) {
    add(1, 1, N, dfn[x], dfn[x] + siz[x] - 1, z);
}
ll op4(int x) {
    return ask(1, 1, N, dfn[x], dfn[x] + siz[x] - 1, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r >> p;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    dfs1(r, r);
    dfs2(r, r);
    for(int i = 0; i < m; i ++) {
        // cout << '\n';
        // for(int i = 1; i <= n; i ++) {
        //     cout << ask(1, 1, MAXN, dfn[i] ,dfn[i] , 0) << '\n';
        // }
        // cout << '\n';
        int op, x, y, z;
        cin >> op;
        if(op == 1) {
            cin >> x >> y >> z;
            op1(x, y, z);
        } else if(op == 2) {
            cin >> x >> y;
            cout << op2(x, y) % p << '\n';
        } else if(op == 3) {
            cin >> x >> z;
            op3(x, z);
        } else {
            cin >> x;
            cout << op4(x) % p << '\n';
        }
    }
}