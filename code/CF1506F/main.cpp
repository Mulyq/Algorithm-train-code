#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i ++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    ll res = 0, t = 0;
    for(int i = 0; i < n; i ++) {
        if((a[i].first - a[i].second) / 2 - t == 0) {
            res += (a[i].first - a[i].second) / 2 - t + (((a[i].first + a[i].second) & 1) == 0 ? (a[i].second - 1) : 0);
        } else {
            res += (a[i].first - a[i].second) / 2 - t;
        }
        t = (a[i].first - a[i].second) / 2;
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