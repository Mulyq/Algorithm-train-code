#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<ll> b(n + 1);
    for(int i = 1; i <= n; i ++) {
        b[i] = a[i] + b[i - 1];
    }
    ll res = 0;
    if(k <= n) {
        for(int i = 1; i <= n; i ++) {
            if(i + k - 1 > n) break;
            res = max(res, b[i + k - 1] - b[i - 1]);
        }
        cout << res + k * (k - 1) / 2 << '\n';
    } else {
        res = b[n] - b[0] + (k - n + k - 1) * n / 2;
        cout << res << '\n'; 
    }
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