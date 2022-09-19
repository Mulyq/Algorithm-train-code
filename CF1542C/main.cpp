#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    ll n;
    cin >> n;
    ll res = 0;
    ll L = 1;
    for(int i = 2; i <= 41; i ++) {
        (res += i * (n / L - n / (L * i / __gcd(L, 1ll * i))) % INF) %= INF;
        L = L * i / __gcd(1ll * i, L);
    }
    cout << res % INF << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while( _ --) {
        solve();
    }
}