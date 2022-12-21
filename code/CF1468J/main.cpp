#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m, k;
struct DSU {
    int N;
    vector<int> pr, sz;
    DSU(int n) : N(n) {
        pr.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 0; i <= n; i ++) {
            pr[i] = i;
            sz[i] = 1;
        }
    }
    int root(int x) {
        return x == pr[x] ? x : pr[x] = root(pr[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[X] = Y;
        sz[Y] += sz[X];
        return 0;
    }
};
struct Edge {
    int x, y, w;
    bool operator< (const Edge & a) const {
        return w < a.w;
    }
};
vector<Edge> mm, mi;
ll res;
void solve() {
    cin >> n >> m >> k;
    res = 1e18;
    DSU dsu(n);
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        res = min(res, 1ll * abs(w - k));
        if(w <= k) {
            mi.push_back({x, y, w});
        } else {
            mm.push_back({x, y, w});
        }
    }
    for(auto &[u, v, w] : mi) {
        dsu.unite(u, v);
    }
    if(dsu.sz[dsu.root(1)] == n) {
        cout << res << '\n';
    } else {
        res = 0;
        sort(mm.begin(), mm.end());
        for(auto &[u, v, w] : mm) {
            if(!dsu.unite(u, v)) {
                res += w - k;
            }
        }
        cout << res << '\n';
    }
    mm.clear(), mi.clear();
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