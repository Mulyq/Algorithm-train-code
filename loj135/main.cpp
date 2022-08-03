#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct dBIT {
    int N, M;
    vector<vector<ll>> p[4];
    dBIT (int n, int m) : N(n), M(m) {
        for(int i = 0; i < 4; i ++) {
            p[i].resize(n + 2, vector<ll> (m + 2));
        }
    }
    void add(int x, int y, int d) {
        for(int i = x; i <= N; i += i & - i) {
            for(int j = y; j <= M; j += j & -j) {
                p[0][i][j] += 1ll * d * x * y;
                p[1][i][j] += 1ll * d * x;
                p[2][i][j] += 1ll * d * y;
                p[3][i][j] += 1ll * d;
            }
        }
    }
    void add(int a, int b, int c, int d, int x) {
        add(a, b, x);
        add(a, d + 1, -x);
        add(c + 1, b, -x);
        add(c + 1, d + 1, x);
    }
    ll ask(int x, int y) {
        ll res = 0;
        for(int i = x; i; i -= i & -i) {
            for(int j = y; j; j -= j & -j) {
                res += p[0][i][j] - (y + 1) * p[1][i][j] - (x + 1) * p[2][i][j] + (x + 1) * (y + 1) * p[3][i][j];
            }
        }
        return res;
    }
    ll ask(int a, int b, int c, int d) {
        return ask(a - 1, b - 1) - ask(a - 1, d) - ask(c, b - 1) + ask(c, d);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dBIT dbit(n, m);
    int op;
    while(cin >> op) {
        int a, b, c, d, x;
        if(op == 1) {
            cin >> a >> b >> c >> d >> x;
            dbit.add(a, b, c, d, x);
        } else {
            cin >> a >> b >> c >> d;
            cout << dbit.ask(a, b, c, d) << '\n';
        }
    }
}