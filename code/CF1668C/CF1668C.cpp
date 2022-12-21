#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    ll ans = 1e18;
    for(int i = 0; i < n; i ++) {
        vector<int> b(n);
        vector<int> res(n);
        ll sum = 0;
        for(int j = i - 1; j >= 0; j --) {
            res[j] = (b[j + 1] + a[j]) / a[j];
            b[j] = res[j] * a[j];
        }
        for(int j = i + 1; j < n; j ++) {
            res[j] = (b[j - 1] + a[j]) / a[j];
            b[j] = res[j] * a[j];
        }
        for(int i = 0; i < n; i ++) {
            sum += res[i];
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}