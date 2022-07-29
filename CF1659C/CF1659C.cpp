#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> pos(n + 1), der(n + 1);
    for(int i = 1; i <= n; i ++) cin >> pos[i];
    for(int i = 1; i <= n; i ++) der[i] = pos[i] - pos[i - 1];
    vector<ll> val(n + 1);
    for(int i = 1; i <= n; i ++) val[i] = val[i - 1] + pos[i];
    ll res = 0;
    ll now = 0;
    ll all = 0;
    for(int i = 1; i <= n; i ++) {
        ll temp = a * (pos[i - 1] - now);
        ll r = b * (val[n] - val[i - 1]) - b * (n - i + 1) * now;
        ll x = temp + b *(val[n] - val[i - 1]) - b * (n - i + 1) * pos[i - 1];
        if(x > r) {
            res += b * (pos[i] - now);
        } else {
            res += a * (pos[i - 1] - now) + b * (pos[i] - pos[i - 1]);
            now = pos[i - 1];
        }
    }
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
    return 0;
}