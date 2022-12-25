#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), r(n);
    map<ll, int> mp;
    ll mir = 1e18;
    for(int i = 0; i < n; i ++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> r[i];
        mp[r[i]] ++;
        mir = min(mir, r[i]);
    }
    vector<ll> a(n);
    for(int i = 1;i < n; i ++) {
        a[i] = x[i] - x[i - 1] - a[i - 1];
    }
    ll mia = 1e18;
    int xl = 0;
    vector<ll> res(n);
    for(int i = 0; i < n; i += 2) {
        if(mia > a[i]) {
            mia = a[i];
            xl = i;
        }
    }
    res[xl] = mir;
    ll X = mir - a[xl];
    multiset<ll> t;
    for(int i = 0; i < n; i ++) {
        if(i & 1) {
            res[i] = a[i] - X;
        } else {
            res[i] = a[i] + X;
        }
        t.insert(res[i]);
    }
    bool ok = 1;
    for(auto &[i, c] : mp) {
        if(t.find(i) == t.end() || c != t.count(i)) {
            ok = 0;
            break;
        }
    }
    if(!ok) {
        mia = 1e18;
        xl = 1;
        for(int i = 1; i < n; i += 2) {
            if(mia > a[i]) {
                mia = a[i];
                xl = i;
            }
        }
        res[xl] = mir;
        X = a[xl] - mir;
        for(int i = 0; i < n; i ++) {
            if(i & 1) {
                res[i] = a[i] - X;
            } else {
                res[i] = a[i] + X;
            }
        }
    }
    for(ll i : res) {
        cout << i << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    while(_ --) {
        solve();
    }
}