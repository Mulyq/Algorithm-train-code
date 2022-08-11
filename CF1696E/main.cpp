#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e6 + 10, mod = 998244353;
ll fact[MAXN], inv[MAXN];
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) (res *= x) %= INF;
        (x *= x) %= INF;
        y >>= 1;
    }
    return res;
}
void init() {
    inv[0] = fact[0] = 1;
    for(int i = 1; i < MAXN; i ++)  {
        fact[i] = fact[i - 1] * i % INF;
    }
    inv[MAXN - 1] = qpow(fact[MAXN - 1], INF - 2);
    for(int i = MAXN - 2; i >= 1; i --) {
        inv[i] = inv[i + 1] * (i + 1) % INF;
    }
}
ll cal(ll n, ll m) {
    return (fact[n] * inv[m] % INF)* inv[n - m] % INF;
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
    cout << res % INF;
    return 0;
}