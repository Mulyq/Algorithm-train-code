#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 1e9+7;
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}
void solve() {
    int T = 1;
    cout << T <<'\n';
    int n = 1e5;
    cout << n << ' ' << 1 << '\n';
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cout << n - i << ' ';
    }
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
}