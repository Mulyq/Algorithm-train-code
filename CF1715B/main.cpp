#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if(s < b * k) {
        cout << -1 << '\n';
        return ;
    }
    vector<ll> a(n);
    a[0] = b * k + k - 1;
    if(a[0] > s) {
        a[0] = s;
    }
    s -= a[0];
    for(int i = 1; i < n && s > 0; i ++) {
        a[i] = min(s, k - 1);
        s -= k - 1;
    }
    if(s > 0) {
        cout << -1 << '\n';
        return ;
    }
    for(ll v : a) {
        cout << v << ' ';
    }
    cout << '\n';
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