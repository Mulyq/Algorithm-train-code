#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int exgcd(int a, int b, int &x, int &y) {
    int d = a;
    if(b) {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1, y = 0;
    }
    return d;
}
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    int d = exgcd(a, b, x, y);
    a /= d, b /= d;
    if(c % d == 0) {
        int k = c / d;
        x *= k, y *= k;
        int t;
        if(x >= 0) {
            t = (int)(x / b + 1);
            x -= t * b;
            y += t * a;
        }
        t = (int)((-x) / b + 1);
        x += b * t;
        y -= a * t;
        // cout << x << ' ' << y << "\n";
        int mxx, mxy, mnx = -1, mny = -1;
        if(y > 0) {
            mxy = y;
            mnx = x;
        } else {
            mxy = x;
        }
        if(y >= 0) {
            t = (int)((y) / a + 1);
            x += t * b;
            y -= t * a;
        }
        t = (int)(- y) / a + 1;
        y += a * t;
        x -= b * t;
        if(x > 0) {
            mny = y;
            mxx = x;
        } else {
            mxx = y;
        }
        if(mnx == -1) {
            cout << mxy <<' ' << mxx << '\n';
        } else {
            cout << (mxx - mnx) / b + 1 << ' ' << mnx << ' ' << mny << ' ' << mxx << ' ' << mxy << '\n';
        }
        // cout << x << ' ' << y << "\n";
    } else {
        cout << -1 << '\n';
    }
    // cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}