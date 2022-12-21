#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10, mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mp(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    ll res = 1;
    int l = mp[0], r = mp[1];
    if(l > r) swap(l , r);
    for(int i = 2; i < n; i ++) {
        int xl = mp[i];
        if(xl < l) {
            l = xl;
        } else if(xl >= l && xl <= r) {
            res = (res * (r - l - i + 1)) % (mod * 1ll);
        } else {
            r = xl;
        }
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