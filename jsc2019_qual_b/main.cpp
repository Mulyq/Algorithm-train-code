#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 1e9 + 7;
struct BIT {
    int N;
    vector<int> s;
    BIT(int n) {
        N = n;
        s.resize(N);
    }
    void add(int x) {
        for(int i = x; i < N; i += i & -i) {
            s[i] ++;
        }
    }
    ll sum(int x) {
        ll res = 0;
        for(int i = x; i; i -= i & -i) {
            res += s[i];
        }
        return res;
    }
};
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            (res *= x) %= mod;
        }
        y >>= 1;
        (x *= x) %= mod;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int A = 0, B = 0;
    BIT bit(2010);
    for(int i = 0; i < n; i ++) {
        A += bit.sum(2000) - bit.sum(a[i]);
        bit.add(a[i]);
    }
    for(int i = 0; i < n; i ++) {
        B += bit.sum(a[i] - 1);
    }
    B = ((1ll * (k - 1) * B % mod) * k % mod) * qpow(2, mod - 2) % mod;
    cout << ((1ll * k * A % mod) + B) % mod;
}