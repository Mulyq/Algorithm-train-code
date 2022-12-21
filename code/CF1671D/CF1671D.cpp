#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int mx = 0, mi = INF;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
    }
    ll res = 0;
    for(int i = 0; i < n - 1; i ++) {
        res += abs(a[i + 1] - a[i]);
    }
    if(x > mx) {
        int all = INF;
        all = min(all, x - a[n - 1]);
        all = min(all, x - a[0]);
        for(int i = 0; i < n - 1; i ++) {
            all = min(all, 2 * x - a[i] - a[i + 1] - abs(a[i + 1] - a[i]));
        }
        res += all;
    }
    if(1 < mi) {
        int all = INF;
        all = min(all, a[n - 1] - 1);
        all = min(all, a[0] - 1);
        for(int i = 0; i < n - 1; i ++) {
            all = min(all, a[i] + a[i + 1] - 2 - abs(a[i + 1] - a[i]));
        }
        res += all;
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