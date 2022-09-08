#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0, mm = INF;
    int res = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mm = min(mm, a[i]);
    }
    for(int i = 0; i < n; i ++) {
        res = max(res, - a[i] + a[(i + n - 1) % n]);
    }
    res = max(res, max(mx - a[0], a[n - 1] - mm));
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