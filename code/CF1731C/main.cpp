#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(2 * n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    ll cnt = 0;
    int x = 0;
    c[x] ++;
    for(int i = 0; i < n; i ++) {
        x ^= a[i];
        for(int j = 0; j * j < 2 * n; j ++) {
            if((x ^ (j * j)) < 2 * n) {
                cnt += c[x ^ (j * j)];
            }
        }
        c[x] ++;
    }
    ll res = 1ll * n * (n + 1) / 2 - cnt;
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