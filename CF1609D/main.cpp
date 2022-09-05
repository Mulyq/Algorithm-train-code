#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct DSU {
    int N;
    vector<int> p, sz;
    DSU(int n) : N(n) {
        p.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 0; i <= n; i ++) {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int root(int x) {
        return x == p[x] ? x : p[x] = root(p[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        p[X] = Y;
        sz[Y] += sz[X];
        return 0;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for(int i = 0; i < n; i ++) {
        s.insert(-1);
    }
    DSU dsu(n);
    int cc = 0;
    while(m -- ) {
        int x, y;
        cin >> x >> y;
        int X = dsu.root(x), Y = dsu.root(y);
        if(X != Y) {
            s.erase(s.find(-dsu.sz[X]));
            s.erase(s.find(-dsu.sz[Y]));
            s.insert(-dsu.sz[X] - dsu.sz[Y]);
            dsu.unite(X, Y);
        } else {
            cc ++;
        }
        int res = 0;
        int temp = cc;
        for(int v : s) {
            res += v;
            temp --;
            if(temp < 0) break;
        }
        std::cout << -res - 1 << '\n';
    }
}