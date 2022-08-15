#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct DSU {
    int N;
    struct block {
        int fa, pos, cnt;
    };
    vector<block> pr;
    DSU(vector<PII> &a) : N(a.size()) {
        pr.resize(N + 1);
        for(int i = 0; i <= N; i ++) {
            pr[i].fa = i, pr[i].pos = i;
            if(a[i].second) pr[i].cnt = 1;
        }
    }
    int root(int x) {
        return x == pr[x].fa ? x : pr[x].fa = root(pr[x].fa);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[X].fa = Y;
        pr[Y].cnt += pr[X].cnt;
        pr[Y].pos = max(pr[X].pos, pr[Y].pos);
        return 0;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<PII> a(n + m + 1);
    vector<PII> qq(q);
    vector<ll> res(q);
    ll sum = 0;
    for(int i = 1; i <= n + m; i ++) {
        cin >> a[i].first;
        if(i <= n) a[i].second = 1, sum += a[i].first;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < q; i ++) {
        cin >> qq[i].first;
        qq[i].second = i;
    }
    sort(qq.begin(), qq.end());
    struct Edge {
        int u, v, derta;
        bool operator< (const Edge& a) const {
            return derta > a.derta;
        }
    };
    DSU dsu(a);
    vector<Edge> G;
    for(int i = 1; i < n + m; i ++) {
        G.push_back({i, i + 1, a[i + 1].first - a[i].first});
    }
    sort(G.begin(), G.end());
    vector<ll> pre(n + m + 1);
    for(int i = 1; i <= n + m; i ++) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    for(auto &[k, xl] : qq) {
        while(G.size() && G.back().derta <= k) {
            int u = G.back().u, v = G.back().v;
            G.pop_back();
            if(!dsu.same(u, v)) {
                u = dsu.root(u), v = dsu.root(v);
                if(dsu.pr[u].pos > dsu.pr[v].pos) swap(u, v);
                sum -= pre[dsu.pr[u].pos] - pre[dsu.pr[u].pos - dsu.pr[u].cnt];
                sum -= pre[dsu.pr[v].pos] - pre[dsu.pr[v].pos - dsu.pr[v].cnt];
                dsu.unite(u, v);
                v = dsu.root(v);
                sum += pre[dsu.pr[v].pos] - pre[dsu.pr[v].pos - dsu.pr[v].cnt];
            }
        }
        res[xl] = sum;
    }
    for(ll vv : res) {
        cout << vv << '\n';
    }
}