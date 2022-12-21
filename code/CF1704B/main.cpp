#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    ll res = 0;
    ll mm = a[0], mx = a[0];
    for(int i = 0, j = 1; j < n;) {
        mm = min(a[j], mm);
        mx = max(mx, a[j]);
        if((mx - mm) > 2 * x) {
            res ++;
            i = j;
            mm = a[j];
            mx = a[j];
        }
        j ++;
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