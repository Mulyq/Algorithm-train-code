#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int mi = INF;
    vector<int> a(n), t1, t2;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i ++) {
        int x;
        cin >> x;
        if(a[i]) t1.push_back(x);
        else t2.push_back(x);
        mi = min(mi, x);
    }
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    ll res = 0;
    if(t1.size() > t2.size()) {
        for(int i = 0; i < t1.size() - t2.size(); i ++) {
            res += t1[i];
        }
        for(int i = t1.size() - t2.size(); i < t1.size(); i ++) {
            res += 2 * t1[i];
        }
        for(int v : t2) {
            res += 2 * v;
        }
    } else if(t2.size() > t1.size()) {
        for(int i = 0; i < t2.size() - t1.size(); i ++) {
            res += t2[i];
        }
        for(int i = t2.size() - t1.size(); i < t2.size(); i ++) {
            res += 2 * t2[i];
        }
        for(int v : t1) {
            res += 2 * v;
        }
    } 
    else {
        for(int i = 0; i < t1.size(); i ++) {
            res += 2ll * t1[i] + 2 * t2[i];
        }
        res -= mi;
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