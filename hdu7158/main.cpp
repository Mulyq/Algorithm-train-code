#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    ll p, q, e;
    cin >> p >> q >> e;
    ll km = p * q - 1, M = -1, res = -1;
    for(int i = 2; i <= km / i; i ++) {
        if(km % i) continue;
        while(km % i == 0) {
            km /= i;
        }
        M = i;
    }
    if(km > 1) M = km;
    if(M > p && M > q) res = 1ll * e * q % M;
    if(res == -1) {
        cout << "shuanQ\n";
    } else {
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