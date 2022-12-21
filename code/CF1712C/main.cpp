#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> ok(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int res = 0;
    for(int l = 0, r = 0; r < n - 1; r ++) {
        if(ok[a[r + 1]]) a[r + 1] = 0;
        if(ok[a[r]]) a[r] = 0;
        if(a[r] > a[r + 1]) {
            for(int i = l; i <= r; i ++) {
                if(!ok[a[i]] && a[i]) res ++;
                ok[a[i]] = 1;
                a[i] = 0;
            }
            l = r + 1;
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