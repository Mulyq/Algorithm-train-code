
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

bool check(ll m, vector<int> &a) {
    ll o = m / 2 + m % 2;
    ll e = m / 2;
    ll all = 0;
    int n = a.size();
    for(int i = 1; i < n; i ++) {
        if(a[i] % 2 == 1) {
            o --;
            all += a[i] - 1;
        } else {
            all += a[i];
        }
    }
    bool ok = 0;
    if(o >= 0 && e >= 0 && all <= o + 2 * e) ok = 1;
    o = m / 2 + m % 2;
    e = m / 2;
    all = 0;
    for(int i = 1; i < n; i ++) {
        if((a[i] + 1) % 2 == 1) {
            o --;
            all += a[i];
        } else {
            all += a[i] + 1;
        }
    }
    if(o >= 1 && all <= o + 2 * e - 1) ok = 1;
    return ok;
}
void solve() {
    int n;
    cin >> n;
    ll res = 1e18;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [&] (const int &a, const int &b) {
        return a > b;
    });
    for(int i = 1; i < n; i ++) {
        a[i] = a[0] - a[i];
    }
    ll l = - 1, r = 1e18;
    while(r - l > 1) {
        ll m = l + r >> 1;
        if(check(m, a)) r = m;
        else l = m;
    }
    cout << r << '\n';
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