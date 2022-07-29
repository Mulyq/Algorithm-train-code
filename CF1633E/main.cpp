#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n, m;
struct Edge {
    int u, v, w;
};
vector<Edge> e;
struct DSU {
    int N;
    vector<int> pr;
    DSU(int n) : N(n) {
        pr.resize(N + 1);
        for(int i = 0; i <= N; i ++) {
            pr[i] = i;
        }
    }
    int root(int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    void unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) {
            return ;
        }
        pr[X] = Y;
    }
};
ll kruskal(int T, int &c) {
    //按照|w - T|排序，但是存在相等的情况要选w更小的，因为在交点左侧|w - T|更小
    sort(e.begin(), e.end(), [&] (const Edge &a, Edge &b) {
        if(abs(a.w - T) != abs(b.w - T))
            return abs(a.w - T) < abs(b.w -T);
        else 
            return a.w < b.w;
    });
    DSU dsu(n);
    int cnt = 0;
    ll res = 0;
    for(auto eg : e) {
        int A = dsu.root(eg.u), B = dsu.root(eg.v);
        if(A == B) continue;
        dsu.unite(A, B);
        cnt ++;
        if(eg.w - T < 0) c ++;
        res += abs(eg.w - T);
        if(cnt == n - 1) {
            break;
        }
    }
    return res;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    //定义了1e9为无穷
    vector<int> pos(1, 1e9);
    for(int i = 0; i < m; i ++) {
        for(int j = i; j < m; j ++) {
    //添加交点到pos
            pos.push_back(e[i].w + e[j].w >> 1);
        }
    }
    sort(pos.begin(), pos.end());
    //去重！
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    vector<ll> dis, cnr;
    for(auto T : pos) {
        int c = 0;
        dis.push_back(kruskal(T, c));
        cnr.push_back(c);
    }
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<int> q(k);
    for(int i = 0; i < k; i ++) {
        if(i < p) {
            cin >> q[i];
        } else {
            q[i] = (1ll * q[i - 1] * a + b) % c;
        }
    }
    ll res = 0;
    for(int i = 0; i < k; i ++) {
        int id = lower_bound(pos.begin(), pos.end(), q[i]) - pos.begin();
        // 生成树价值偏移量的计算
        ll D = dis[id] - (cnr[id] * (pos[id] - q[i])) - (n - 1 - cnr[id]) * (q[i] - pos[id]);
        // cout << D << '\n';
        res ^= D;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}