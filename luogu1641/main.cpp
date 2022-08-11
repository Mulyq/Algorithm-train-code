#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e6 + 10, mod = 20100403;
ll fact[MAXN], inv[MAXN];
int n, m;
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            (res *= x) %= mod;
        }
        (x *= x) %= mod;
        y >>= 1;
    }
    return res;
}
void init() {
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n + m; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[n + m] = qpow(fact[n + m], mod - 2);
    for(int i = n + m - 1; i > 0; i --) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
ll C(ll m, ll n) {
    ll res = 1;
    (res *= fact[m]) %= mod;
    (res *= (inv[m - n] * inv[n]) % mod) %= mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    ll res = 0;
    res += (C(n + m, m) - C(n + m, m - 1) + mod) % mod;
    // ll t = n - m;
    // (res *= qpow(2 * n + 1, t) * inv[n - m] % mod) %= mod;
    cout << res % mod;
}