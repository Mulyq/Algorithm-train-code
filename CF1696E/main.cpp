#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10, mod = 1e9 + 7;
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll res = 0;
    init();
    for(int i = 0; i <= n; i ++) {
        int a;
        cin >> a;
        res += cal(i + a, i + 1);
    }
    cout << res % mod;
    return 0;
}