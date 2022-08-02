#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
struct dBIT {
    int N, M;
    vector<vector<ll>> p;
    dBIT (int n, int m) : N(n), M(m) {
        p.resize(n + 1, vector<ll> (m + 1));
    }
    void add(int x, int y, int d) {
        for(int i = x; i <= N; i += i & -i) {
            for(int j = y; j <= M; j += j & -j) {
                p[i][j] += d;
            }
        }
    }
    ll ask(int x, int y) {
        ll res = 0;
        for(int i = x; i; i -= i & - i) {
            for(int j = y; j ; j -= j & -j) {
                res += p[i][j];
            }
        }
        return res;
    }

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dBIT dbit(n, m);
    int op;
    while(cin >> op) {
        if(op == 1) {
            int a1, b1, a2, b2, d;
            cin >> a1 >> b1 >> a2 >> b2 >> d;
            dbit.add(a1, b1, d);
            dbit.add(a2 + 1, b1, -d);
            dbit.add(a1, b2 + 1, -d);
            dbit.add(a2 + 1, b2 + 1, d);
        } else {
            int x, y;
            cin >> x >> y;
            cout << dbit.ask(x, y) << '\n';
        }
    }
}