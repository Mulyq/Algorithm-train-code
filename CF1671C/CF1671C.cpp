#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i ++) {
        b[i] = b[i - 1] + a[i];
    }
    ll all = 0;
    ll res = 0;
    for(int i = n; i ; i --) {
        if(x < b[i]) continue;
        ll day = (x - b[i]) / i + 1ll;
        res += i * (day - all);
        all = day;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}