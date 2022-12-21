#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, q;
vector<int> e[MAXN];
int dep[MAXN], fa[MAXN], hson[MAXN], siz[MAXN], top[MAXN], dfn[MAXN], tim, rnk[MAXN];

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
            hson[r] = v;
            maxsonsize = siz[v];
        }
    }
}
void dfs2(int r, int topf) {
    top[r] = topf;
    dfn[r] = ++ tim;
    rnk[tim] = r;
    if(hson[r] == - 1) return ;
    dfs2(hson[r], topf);
    for(int v : e[r]) if(v != fa[r] && v != hson[r]) {
        dfs2(v, v);
    }
}

int v[MAXN << 2], d[2][MAXN << 2]; // 任意， 存在

void updata(int k, int l, int r) {
    if(v[k] & 8) {
        v[k] ^= 8;
        d[0][k << 1] = d[0][k << 1 | 1] = 0;
        d[1][k << 1] = d[1][k << 1 | 1] = 0;
        v[k << 1] = v[k << 1 | 1] = 8;
    }
    if(v[k]) {
        v[k << 1] |= v[k];
        v[k << 1 | 1] |= v[k];
        d[1][k << 1] |= v[k];
        d[0][k << 1] |= v[k];
        d[1][k << 1 | 1] |= v[k];
        d[0][k << 1 | 1] |= v[k];
        v[k] = 0;
    }
}

void add(int k, int l, int r, int s, int t, int x) {
    if(l == s && r == t) {
        if(x == 8) {
            v[k] = x;
            d[1][k] = 0;
            d[0][k] = 0;
        } else {
            v[k] |= x;
            d[1][k] |= x;
            d[0][k] |= x;
        }
        // cout << l << ' ' << r << '\n';
    } else {
        updata(k, l, r);
        int m = l + r >> 1;
        if(m >= t) {
            add(k << 1, l, m, s, t, x);
        } else if(s >= m + 1) {
            add(k << 1 | 1, m + 1, r, s, t, x);
        } else {
            add(k << 1, l, m, s, m, x);
            add(k << 1 | 1, m + 1, r, m + 1, t, x);
        }
        d[1][k] = d[1][k << 1] & d[1][k << 1 | 1];
        d[0][k] = d[0][k << 1] | d[0][k << 1 | 1];
    }
}
int ask(int k = 1, int l = 1, int r = n) {
    // cout << l << ' ' << r << ' ' << d[1][k] << '\n';
    if((d[1][k] & 7) == 7) {
        // cout << rnk[l] << ' ' << rnk[r] << '\n';
        // cout << r - l + 1 << '\n' << '\n';
        return r - l + 1;
    }
    if(l == r) return 0;
    updata(k, l, r);
    int m = l + r >> 1;
    int res = 0;
    if((d[0][k << 1] & 7) == 7) {
        res += ask(k << 1, l, m);
    }
    if((d[0][k << 1 | 1] & 7) == 7) {
        res += ask(k << 1 | 1, m + 1, r);
    }
    return res;
}
void solve() {
    cin >> n >> q;
    for(int i = 2; i <= n; i ++) {
        int r;
        cin >> r;
        e[r].push_back(i);
        // e[i].push_back(r);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    while(q --) {
        // memset(d, 0,sizeof d);
        // memset(v, 0,sizeof v);
        int a, b, c, x;
        cin >> a >> b >> c;
        for(int i = 0; i < a; i ++) {
            cin >> x;
            do {
                int l = dfn[top[x]], r = dfn[x];
                add(1, 1, n, l, r, 1);
                x = fa[top[x]];
            } while(fa[x] != x);
        }
        for(int i = 0; i < b; i ++) {
            cin >> x;
            do {
                int l = dfn[top[x]], r = dfn[x];
                add(1, 1, n, l, r, 2);
                x = fa[top[x]];
            } while(fa[x] != x);
        }
        for(int i = 0; i < c; i ++) {
            cin >> x;
            add(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, 4);
        }
        cout << ask() << '\n';
        add(1, 1, n, 1, n, 8);
    }
}

void init() {
    tim = 0;
    for(int i = 1; i <= n; i ++) {
        e[i].clear();
    }
    memset(d, 0,sizeof d);
    memset(v, 0,sizeof v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        init();
        solve();
    }
    return 0;
}