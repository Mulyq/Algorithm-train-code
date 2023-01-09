#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    ll n;
    cin >> n;
    ll inv3 = 333333336;
    ll inv2 = INF + 1 >> 1;
    ll res = n * (n + 1) % INF * (2 * n + 1) % INF * inv3 % INF;
    res -= 1 + (n + 2) * (n - 1) % INF * inv2 % INF;
    
    res = (res + INF) % INF;
    res = res * 2022 % INF;
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
}