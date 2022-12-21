#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    ll res = 1e18;
    if(n % 2 == 1) {
        res = 0;
        for(int i = 1; i + 1 < n; i += 2) {
            res += max(0, max(a[i + 1], a[i - 1]) - a[i] + 1);
        }
    } else {
        vector<ll> c1(n);
        vector<ll> c2(n);
        for(int i = 1; i + 1 < n; i += 2) {
            c1[i] = max(0, max(a[i + 1], a[i - 1]) - a[i] + 1);
        }
        for(int i = 2; i + 1 < n; i += 2) {
            c2[i] = max(0, max(a[i + 1], a[i - 1]) - a[i] + 1);
        }
        for(int i = 1; i < n; i ++) {
            c1[i] += c1[i - 1];
            c2[i] += c2[i - 1];
        }
        for(int i = 0; i < n / 2; i ++) {
            ll t = 0;
            t += c1[i * 2] - c1[0] + c2[n - 1] - c2[i * 2];

            // for(int j = 1; j + 1 < n; j += 2) {
            //     if(j / 2 == i) j ++;
            //     t += max(0, max(a[j + 1], a[j - 1]) - a[j] + 1);
            // }
            res = min(res, t);
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