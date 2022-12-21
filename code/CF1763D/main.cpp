#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 120, mod = 1e9 + 7;
ll fact[MAXN], inv[MAXN];
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return res;
}
void init() {
    inv[0] = fact[0] = 1;
    for(int i = 1; i < MAXN; i ++)  {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[MAXN - 1] = qpow(fact[MAXN - 1], mod - 2);
    for(int i = MAXN - 2; i >= 1; i --) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
ll cal(ll n, ll m) {
    if(n < 0 || m < 0) return 0;
    if(n < m) return 0;
    return (fact[n] * inv[m] % mod)* inv[n - m] % mod;
}
void solve() {
    int n, i, j, x, y;
    cin >> n >> i >> j >> x >> y;
    if(x > y) {
        i = n - i + 1, j = n - j + 1;
        swap(i, j), swap(x, y);
    }
    if(y == n) {
        if(j == n) {
            cout << 0 << '\n';
        } else {
            cout << cal(x - 1, i - 1) * cal(y - x - 1, j - i - 1) % mod << '\n';
        }
        return;
    }
    ll res = 0;
    for(int m = i + 1; m < n; m ++) {
        if(m == j) continue;
        if(m < j) {
            int t = n - y - j + m;
            if(t < 0) continue;
            res += (cal(x - 1, i - 1) * cal(n - y - 1, j - m - 1) % mod) * cal(n - x - j + m - 1 - t, m - i - 1 - t) % mod;
        } else {
            res += (cal(x - 1, i - 1) * cal(y - x - 1, j - i - 1) % mod) * cal(n - y - 1, m - j - 1) % mod;
        }
        res %= mod;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}