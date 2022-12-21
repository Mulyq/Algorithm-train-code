#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m, e;
vector<PII> edge;
struct DSU {
    int N;
    vector<int> p, city, ex;
    DSU() {
        N = n + m;
        p.resize(N);
        city.resize(N);
        ex.resize(N);
        for(int i = 0; i < N; i ++) {
            p[i] = i;
            if(i < n) {
                city[i] = 1;
            } else {
                ex[i] = 1;
            }
        }
    }
    int root(int x) {
        return p[x] == x ? x : p[x] = root(p[x]);
    }
    void unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return ;
        ex[X] = max(ex[X], ex[Y]);
        city[X] += city[Y];
        p[Y] = X;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> e;
    for(int i = 0; i < e; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        edge.push_back({u, v});
    }
    DSU dsu;
    int q;
    cin >> q;
    vector<int> query(q);
    vector<int> tt(e, 1);
    for(int i = 0; i < q; i ++) {
        int x;
        cin >> x;
        x --;
        query[i] = x;
        tt[x] = 0;
    }
    for(int i = 0; i < edge.size(); i ++) if(tt[i]) {
        dsu.unite(edge[i].first, edge[i].second);
    }
    vector<ll> res(q);
    vector<int> vis(n + m);
    for(int i = 0; i < n; i ++) {
        int R = dsu.root(i);
        if(vis[R]) continue;
        vis[R] = 1;
        if(dsu.ex[R]) {
            res[0] += dsu.city[R];
        }
    }
    reverse(query.begin(), query.end());
    for(int i = 1; i < q; i ++) {
        int u = edge[query[i - 1]].first, v = edge[query[i - 1]].second;
        res[i] = res[i - 1];
        int A = dsu.root(u), B = dsu.root(v);
        if(A != B) {
            if(dsu.ex[A] && !dsu.ex[B]) {
                res[i] += dsu.city[B];
            }
            if(dsu.ex[B] && !dsu.ex[A]) {
                res[i] += dsu.city[A];
            }
            dsu.unite(A, B);
        }
    }
    for(int i = q - 1; i >= 0; i --) {
        cout << res[i] << '\n';
    }
}