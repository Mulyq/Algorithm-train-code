#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if(b) {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1, y = 0;
    }
    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> k;
    ll res = 0;
    for(ll a = 1, b = 1, t; a + b <= k; t = b, b = a + b, a = t) {
        ll x, y;
        ll d = exgcd(a, b, x, y);
        if(k % d != 0) continue;
        x *= k / d, y *= k / d;
        ll xl, xr, yl, yr;
        xl = (x % b + b) % b;
        if(!xl) xl = b;
        yr = (k - a * xl) / (b);
        yl = (y % a + a) % a;
        if(!yl) yl = a;
        xr = (k - b * yl) / (a);
        res += (xr - xl) / b + 1;
    }
    cout << res % INF << '\n';
}