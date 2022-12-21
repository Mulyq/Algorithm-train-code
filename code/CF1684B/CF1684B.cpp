#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y, z;
    z = c, y = b;
    ll l = 1, r = 1e8 + 10;
    while(r - l > 1) {
        ll m = (l + r) / 2ll;
        ll w = m * b + a;
        if(w > c) {
            x = w;
            break;
        } else {
            l = m;
        }
    }
    cout << x << ' ' <<  y << ' ' << z << '\n';
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