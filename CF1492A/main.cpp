#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    a = a * (ll)((p + a - 1) / a);
    b = b * (ll)((p + b - 1) / b);
    c = c * (ll)((p + c - 1) / c);
    cout << min({a, b, c}) - p << "\n";
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