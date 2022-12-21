#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 5e3 + 10;
int n;
int mod;
ll fact[MAXN], inv[MAXN];
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
    inv[0] = fact[0] = 1;
    for(int i = 1; i < MAXN; i ++)  {
        fact[i] = fact[i - 1] * i % mod;
    }
}
void solve() {
    cin >> n >> mod;
    init();
    ll res = 1;
    if(n % 2 == 0) {
        res *= n * fact[n / 2];
        res %= mod;
        ll t = 0;
        for(int i = 0; i <= n / 2 - 1; i ++){
            t += fact[i];
            t %= mod;
        }
        res *= t;
        res %= mod;
    } else {
        res *= n * fact[n / 2];
        res %= mod;
        ll t = 0;
        for(int i = 0; i <= n / 2 - 1; i ++) {
            t += fact[i];
            t %= mod;
        }
        res *= t;
        res %= mod;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    while(_ --) {
        solve();
    }
}