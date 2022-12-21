#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 70, mod = 998244353;
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
    return (fact[n] * inv[m] % mod)* inv[n - m] % mod;
}
void solve() {
    ll a = 0, b = 0, ab = 1;
    int n;
    cin >> n;
    for(int i = 0; n / 2 - i - 1 >= 0; i += 2) {
        a += cal(n - 1 - 2 * i, n / 2 - i - 1);
        b += cal(n - 2 - 2 * i, n / 2 - i - 2);
    }
    for(int i = 1; n / 2 - i - 1 >= 0; i += 2) {
        b += cal(n - 1 - 2 * i, n / 2 - i - 1);
        a += cal(n - 2 - 2 * i, n / 2 - i - 2);
    }
    
    cout << a % mod << ' ' << b % mod << ' ' << ab << '\n';
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
    return 0;
}