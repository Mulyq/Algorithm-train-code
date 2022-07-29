#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    ll res = 1e18;
    res = min(res, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    res = min(res, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    ll temp = abs(a[0] - b[0]) + abs(a[0] - b[n - 1]);
    for(int i = 1; i < n - 1; i ++) {
        res = min(res, temp + abs(a[n - 1] - b[i]));
    }

    temp = abs(a[n - 1] - b[0]) + abs(a[n - 1] - b[n - 1]);
    for(int i = 1; i < n - 1; i ++) {
        res = min(res, temp + abs(a[0] - b[i]));
    }

    temp = abs(b[0] - a[0]) + abs(b[0] - a[n - 1]);
    for(int i = 1; i < n - 1; i ++) {
        res = min(res, temp + abs(b[n - 1] - a[i]));
    }

    temp = abs(b[n - 1] - a[0]) + abs(b[n - 1] - a[n - 1]);
    for(int i = 1; i < n - 1; i ++) {
        res = min(res, temp + abs(b[0] - a[i]));
    }

    temp = abs(a[0] - b[0]);
    ll c = INF, d = INF;
    for(int i = 0; i < n - 1; i ++) {
        c = min(c, abs(a[n - 1] - b[i]));
        d = min(d, abs(b[n - 1] - a[i]));
    }
    res = min(res, temp + c + d);

    temp = abs(a[0] - b[n - 1]);
    c = INF, d = INF;
    for(int i = 0; i < n - 1; i ++) {
        c = min(c, abs(a[n - 1] - b[i]));
        d = min(d, abs(b[0] - a[i]));
    }
    res = min(res, temp + c + d);

    temp = abs(a[n - 1] - b[0]);
    c = INF, d = INF;
    for(int i = 0; i < n - 1; i ++) {
        c = min(c, abs(a[0] - b[i]));
        d = min(d, abs(b[n - 1] - a[i]));
    }
    res = min(res, temp + c + d);

    temp = abs(a[n - 1] - b[n - 1]);
    c = INF, d = INF;
    for(int i = 0; i < n - 1; i ++) {
        c = min(c, abs(a[0] - b[i]));
        d = min(d, abs(b[0] - a[i]));
    }
    res = min(res, temp + c + d);

    ll x[4];
    memset(x, 0x3f, sizeof x);
    for(int i = 1; i < n - 1;i ++) {
        x[0] = min(x[0], abs(a[0] - b[i]));
        x[1] = min(x[1], abs(a[n - 1] - b[i]));
        x[2] = min(x[2], abs(b[0] - a[i]));
        x[3] = min(x[3], abs(b[n  - 1] - a[i])); 
    }
    res = min(res, 1ll * x[0] + x[1] + x[2] + x[3]);
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}