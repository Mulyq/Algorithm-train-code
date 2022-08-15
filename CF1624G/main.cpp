#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct DSU {
    int N;
    vector<int> pr, siz;
    DSU(int n) : N(n) {
        pr.resize(n + 1);
        siz.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            pr[i] = i, siz[i] = 1;
        }
    }
    int root(int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[X] = Y;
        siz[Y] += siz[X];
        return 0;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    struct Edge {
        int u, v, w;
    };
    vector<Edge> G(m);
    for(auto &[u, v, w] : G) {
        cin >> u >> v >> w;
    }
    int res = 0;
    for(int i = 29; i >= 0; i --) {
        int cur = res + (1 << i);
        DSU dsu(n);
        for(auto &[u, v, w] : G) {
            if(!(cur & w)) {
                dsu.unite(u, v);
            }
        }
        if(dsu.siz[dsu.root(1)] == n) {
            res = cur;
        }
    }
    cout << (1 << 30) - 1 - res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}