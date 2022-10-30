#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), pos(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    if(n == 1) {
        cout << "1\n";
        return ;
    }
    ll res = 0;
    int l = n, r = - 1;
    for(int i = 1; i <= n; i ++) {
        l = min(l, pos[i - 1]), r = max(r, pos[i - 1]);
        while(i < n && pos[i] >= l && pos[i] <= r) i ++;
        if(i == n) {
            res ++;
            break;
        }
        int len = 2 * i;
        if(r - l + 1 > len) continue;
        int _l = 0, _r = n - 1;
        if(pos[i] > r) {
            _r = pos[i] - 1;
            for(int j = r; j <= _r; j ++) {
                if(j - l + 1 > len) continue;
                res += min(len - (j - l + 1) + 1, l - _l + 1);
            }
        } else {
            _l = pos[i] + 1;
            for(int j = l; j >= _l; j --) {
                if(r -j + 1 > len) continue;
                res += min(len - (r - j + 1) + 1, _r - r + 1);
            }
        }
    }
    cout << max(1ll, res) << '\n';
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