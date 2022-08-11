#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2333, mod = 2333;
ll fact[mod], inv[mod], ff[MAXN][MAXN], kkk[MAXN][MAXN];
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
    for(int i = 1; i < MAXN; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[MAXN - 1] = qpow(fact[MAXN - 1], mod - 2); 
    for(int i = mod - 2; i > 0; i --) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
ll C(ll n, ll m) {
    if(m > n) return 0;
    return (fact[n] * inv[m] % mod) * inv[n - m] % mod;
}
ll mp[MAXN], cc[MAXN][MAXN];
ll lucas(ll n, ll m) {
    if(m == 0) return 1;
    return C(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}

ll f(ll n, ll k) {
    if(k < 0) return 0;
    if(!n || !k) return 1;
    if(n < MAXN && k < MAXN && ff[n][k] >= 0) {
        return ff[n][k];
    }
    ll res = 0;
    ll kk = lucas(n / mod, k / mod) % mod;
    ll tt = 0;
    if(kkk[n % mod][k % mod] >= 0) {
        tt = kkk[n % mod][k % mod];
    } else {
        for(int i = 0; i <= k % mod; i ++) {
            ll t;
            if(cc[n % mod][i] >= 0) {
                t = cc[n % mod][i];
            } else {
                t = cc[n % mod][i] = lucas(n % mod, i);
            }
            (tt += t % mod) %= mod;
        }
        kkk[n % mod][k % mod] = tt;
    }
    res += tt * kk % mod;
    if (k < mod) {
        if(n < MAXN && k < MAXN) ff[n][k] = res;
        return res % mod;
    }
    ll all = 0;
    if(mp[n % mod] >= 0) {
        all = mp[n % mod];
    } else {
        for(int i = 0; i < mod; i ++) {
            (all += C(n % mod, i)) %= mod;
        }
        mp[n % mod] = all;
    }
    (res += (f(n / mod, k / mod - 1) * all) % mod) %= mod;
    if(n < MAXN && k < MAXN) ff[n][k] = res;
    return res % mod;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    ll res = f(n, k);
    cout << res % mod << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(mp, -1, sizeof mp);
    memset(cc, -1, sizeof cc);
    memset(kkk, -1, sizeof kkk);
    memset(ff, -1, sizeof ff);
    init();
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}