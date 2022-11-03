#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    ll res = 0;
    // ll res = max(2 * a[n - 1] - a[n - 2] - a[0], a[n - 1] + a[1] - 2 * a[0]);
    for(int i = 1; i < n; i ++) {
        res = max(res, 2ll * a[n - i] - a[n - i - 1] - a[0]);
        res = max(res, 1ll * a[n - 1] + a[i] - 2 * a[i - 1]);
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
}