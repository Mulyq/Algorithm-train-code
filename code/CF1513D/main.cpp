#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct DSU {
    int N;
    vector<int> pr;
    vector<ll> val;
    DSU(int n) : N(n) {
        pr.resize(n + 1);
        val.resize(n + 1);
        for(int i = 0; i <= n; i ++) {
            pr[i] = i;
        }
    }
    int root(int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[X] = Y;
        val[Y] += val[X];
        return 0;
    }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), rk(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        rk[i] = i;
    }
    sort(rk.begin(), rk.end(), [&] (int x, int y) {
        return a[x] < a[y];
    });
    DSU dsu (n);
    for(int i = 0; i < n; i ++) {
        if(a[rk[i]] >= k) break;
        int x = rk[i];
        queue<int> q;
        if(rk[i] > 0) q.push(rk[i] - 1);
        if(rk[i] < n - 1) q.push(rk[i] + 1);
        while(q.size()) {
            int y = q.front();
            q.pop();
            if(a[y] % a[x] == 0 && !dsu.unite(x, y)) {
                dsu.val[dsu.root(x)] += a[x];
                if(y < x && y - 1 >= 0) {
                    q.push(y - 1);
                } else if(y > x && y + 1 < n) {
                    q.push(y + 1);
                }
            }
        }
    }
    for(int i = 0; i < n - 1; i ++) {
        if(!dsu.unite(i, i + 1)) {
            dsu.val[dsu.root(i)] += k;
        }
    }
    cout << dsu.val[dsu.root(0)] << '\n';
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