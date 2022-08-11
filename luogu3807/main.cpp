#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
ll fact[MAXN], inv[MAXN];
ll qpow(ll x, ll y, ll p) {
    ll res = 1;
    if(y) {
        if(y & 1) (res *= x) %= p;
        (x *= x) %= p;
        y >>= 1;
    }
    return res;
}
void init(int p) {
    fact[0] = inv[0] = 1;
    for(int i = 1; i < p; i ++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
    inv[p - 1] = qpow(fact[p - 1], p - 2, p);
    for(int i = p - 2; i > 0; i --) {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}
ll C (ll n, ll m, ll p) {
    ll res = (fact[n] * inv[m] % p) * inv[n - m] % p;
    return res;
}
ll lucas(ll n, ll m, ll p) {
    if(m == 0) return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
void solve() {
    int n , m , p;
    cin >> n >> m >> p;
    init(p);
    cout << lucas(n + m, m, p) << '\n';
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