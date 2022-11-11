#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
#define int ll
struct BIT {
	int N;
	vector<ll> p;
	BIT(int n) : N (n) {
		p.resize(n + 2);
	}
	void add(int x, int d) {
		for(; x <= N; x += x & -x) {
			(p[x] += d) %= mod;
		}
	}
	ll ask(int x) {
		ll res = 0;
		for(; x; x -= x & -x) {
			(res += p[x]) %= mod;
		}
		return res;
	}
	ll ask(int l, int r) {
		return ask(r) - ask(l - 1);
	}
};
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    BIT bit(2e5 + 10), bit2(2e5 + 10);
    int n;
    ll all = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        all += x * (2ll * bit.ask(x) + 1) % mod;
        all %= mod;
        all += 2ll * (bit2.ask(2e5 + 5) - bit2.ask(x) + mod) % mod;
        all %= mod;
        cout << all * qpow(((i + 1) * (i + 1)) % mod, mod - 2) % mod << '\n';
        bit.add(x, 1);
        bit2.add(x, x);
    }
}