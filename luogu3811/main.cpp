#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 4e6 + 10, mod = 998244353;
ll fact[MAXN], inv[MAXN];
ll p, n;
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) (res *= x) %= p;
        (x *= x) %= p;
        y >>= 1;
    }
    return res;
}
void solve() {
    inv[0] = fact[0] = 1;
    for(int i = 1; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % p;
    }
    inv[n] = qpow(fact[n], p - 2);
    for(int i = n - 1; i > 0; i --) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
    }
}
void sec() {
    inv[1] = 1;
    for(int i = 2; i <= n; ++ i)
        inv[i] = (p - p / i) * inv[p % i] % p;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    // solve();
    // for(int i = 1; i <= n; i ++) {
    //     cout << (fact[i - 1] * inv[i]) % p << '\n';
    // }
    sec();
    for(int i = 1; i <= n; i ++) {
        cout << inv[i] << '\n';
    }
    return 0;
}