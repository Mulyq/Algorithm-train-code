#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    ll res = 0, b = 0, l = 0;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        l = max(l, 1ll * y);
        b += x;
    }
    res = 2 * (l + b);
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