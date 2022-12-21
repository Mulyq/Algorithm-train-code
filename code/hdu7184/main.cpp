#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> d(64);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        for(int j = 63; j >= 0; j --) {
            if(a[i] & (1ll << j)) {
                if(!d[j]) {
                    d[j] = a[i];
                    break;
                } else {
                    a[i] ^= d[j];
                }
            }
        }
    }
    ll res = 0;
    for(int i = 63; i >= 0; i--) {
        res = max(res, res ^ d[i]);
    }
    for(int i = 63; i >= 0; i--) {
        if(res < (res ^ d[i])) {
            res ^= d[i];
        }
    }
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