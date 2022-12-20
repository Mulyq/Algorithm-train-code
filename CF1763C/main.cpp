#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 120, mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll res = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (n == 2) {
        res = max(2 * abs(a[1] - a[2]), (a[1] + a[2]));
        cout << res << '\n';
        return;
    } else if (n > 3) {
        ll mx = a[1];
        for(int i = 1; i <= n; i ++) {
            mx = max(mx, a[i]);
        }
        cout << mx * n << '\n';
    } else if (n == 3) {
        res = a[1] + a[2] + a[3];
        res = max(max(a[1] * 3, res), max(a[3] * 3, res));
        res = max(max(abs(a[1] - a[2]) * 3, res), max(abs(a[2] - a[3]) * 3, res));
        cout << res << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}