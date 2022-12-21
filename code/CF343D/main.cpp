#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 5e5 + 10, mod = 998244353;
vector<vector<int>> G;
int dep[MAXN], fa[MAXN], dfn[MAXN], top[MAXN], siz[MAXN], hson[MAXN], tim;
int n, q;
void dfs1(int u ,int f) {
    siz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f] + 1;
    hson[u] = -1;
    int maxs = -1;
    for(int v : G[u]) if(v != f) {
        dfs1(v, u);
        siz[u] += siz[v];
        if(maxs < siz[v]) {
            maxs = siz[v];
            hson[u] = v;
        }
    }
}
void dfs2(int u, int topf) {
    dfn[u] = ++ tim;
    top[u] = topf;
    if(hson[u] == - 1) return ;
    dfs2(hson[u], topf);
    for(int v : G[u]) if(v != fa[u] && v != hson[u]) {
        dfs2(v, v);
    }
}

struct segtre {
    int N;
    vector<int> p, v, ch;
    segtre(int n) : N(n) {
        p.resize((n << 2) + 1);
        ch.resize((n << 2) + 1);
        v.resize((n << 2) + 1);
    }
    void push_down(int k, int l, int r) {
        if(v[k]) {
            int m = l + r >> 1;
            p[k << 1] = (m - l + 1) * ch[k], p[k << 1 | 1] = (r - m) * ch[k];
            v[k << 1] = v[k << 1 | 1] = v[k];
            ch[k << 1] = ch[k << 1 | 1] = ch[k];
            ch[k] = 0;
            v[k] = 0;
        }
    }
    void up_data(int k, int l, int r) {
        int m = l + r >> 1;
        p[k] = p[k << 1] + p[k << 1 | 1];
    }
    void add(int k, int l, int r, int s, int t, int x) {
        if(l == s && r == t) {
            ch[k] = x;
            v[k] = 1;
            p[k] = x * (t - s + 1);
            return ;
        }
        push_down(k, l, r);
        int m = l + r >> 1;
        if(m >= t) {
            add(k << 1, l, m, s, t, x);
        } else if(s >= m + 1) {
            add(k << 1 | 1, m + 1, r, s, t, x);
        } else {
            add(k << 1, l, m, s, m, x);
            add(k << 1 | 1, m + 1, r, m + 1, t, x);
        }
        // up_data(k, l, r);
    }
    int ask(int k, int l, int r, int s, int t) {
        if(l == s && r == t) {
            return p[k];
        }
        push_down(k, l, r);
        int m = l + r >> 1;
        int res = 0;
        if(m >= t) {
            res = ask(k << 1, l, m, s, t);
        } else if(s >= m + 1) {
            res = ask(k << 1 | 1, m + 1, r, s, t);
        } else {
            res = ask(k << 1, l, m, s, m) + ask(k << 1 | 1, m + 1, r, m + 1, t);
        }
        // up_data(k, l, r);
        return res;
    }
};
void op1(int x, segtre &st) {
    st.add(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, 1);
}
void op2(int x, segtre &st) {
    if(top[x] != 1) {
        st.add(1, 1, n, dfn[top[x]], dfn[x], 0);
        op2(fa[top[x]], st);
    } else {
        st.add(1, 1, n, 1, dfn[x], 0);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    G.resize(n + 1);
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    segtre st(n);
    cin >> q;
    while(q --) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            op1(x, st);
        } else if(op == 2) {
            op2(x, st);
        } else {
            cout << st.ask(1, 1, n, dfn[x], dfn[x]) << '\n';
        }
    }
}