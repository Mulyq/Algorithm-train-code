#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    double all = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        all += a[i];
    }
    double res1 = 0, res2 = 0;
    if(all <= 100) {
        res1 += all;
    } else if(all <= 100 + 100 / 0.8) {
        res1 += 100 + (all - 100) * 0.8;
    } else {
        res1 += 100 + 100 + (all - 100 - 100 / 0.8) * 0.5;
    }

    double cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(cnt < 100) {
            res2 += a[i];
            cnt += a[i];
        } else if(cnt < 200) {
            res2 += a[i] * 0.8;
            cnt += a[i] * 0.8;
        } else {
            res2 += a[i] * 0.5;
            cnt += a[i] * 0.5;
        }
    }
    printf("%.3f %.3f\n", res1, res2);
    // cout << res1 << ' ' << res2 << '\n';
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}