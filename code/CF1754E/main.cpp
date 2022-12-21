#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int c = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        c += a[i];
    }
    c = n - c;
    int w = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i]) {
            if(i < c) {
                w ++;
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= w; i ++) {
        ll x = (1ll * i * i) % mod;
        (res += qpow(x, mod - 2)) %= mod;
    }
    res = ((1ll * n * (n - 1) % mod) * qpow(2, mod - 2) % mod) * res % mod;
    cout << res << '\n';
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