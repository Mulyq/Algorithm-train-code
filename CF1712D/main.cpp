#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int l, r;
    cin >> l >> r;
    ll res = 0;
    res += 1ll * (r - l + 1) * (r - l) * (r - l - 1) / 6;
    for(int i = l + 2; i <= r; i ++) {
        ll c = 0;
        for(int j = l; j <= i / j; j ++) {
            if(i % j == 0) {
                int w = i / j;
                if(w > j && w < i) {
                    c ++;
                }
                if(2 * j < i && w >= l && w < i && 2 *j + w > i) {
                    c ++;
                }
            }
        }
        res -= c;
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