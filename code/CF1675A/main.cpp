#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    x -= a, y -= b;
    if(x > 0) {
        c -= x;
    }
    if(y > 0) {
        c -= y;
    }
    if(c < 0) cout << "NO\n";
    else cout << "YES\n";
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