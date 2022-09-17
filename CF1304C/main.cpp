#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    struct p {
        int t, l, r;
        bool operator< (const p &a) const {
            return t < a.t;
        }
    };
    int n, m;
    cin >> n >> m;
    vector<p> a(n);
    for(auto &[t, l, r] : a) {
        cin >> t >> l >> r;
    }
    a.push_back({0, m, m});
    sort(a.begin(), a.end());
    ll L = m, R = m;
    for(int i = 1; i <= n; i ++) {
        L -= a[i].t - a[i - 1].t;
        R += a[i].t - a[i - 1].t;
        if(a[i].l > R || a[i].r < L) {
            cout << "NO\n";
            return;
        } else {
            L = max(L, 1ll * a[i].l);
            R = min(R, 1ll * a[i].r);
        }
    }
    cout << "YES\n";
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