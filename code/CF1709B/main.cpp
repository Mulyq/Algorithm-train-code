#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<ll> pre;
    pre.push_back(0);
    for(int i = 1; i < n; i ++) {
        pre.push_back(max(0, - a[i] + a[i - 1]));
    }
    for(int i = 1; i < n; i ++) {
        pre[i] += pre[i - 1];
    }
    vector<ll> tai;
    tai.push_back(0);
    for(int i = n - 2; i >= 0; i --) {
        tai.push_back(max(0, - a[i] + a[i + 1]));
    }
    // reverse(tai.begin(), tai.end());
    for(int i = 1; i < n; i++) {
        tai[i] += tai[i - 1];
    }
    while(m --) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l < r) {
            cout << pre[r] - pre[l] << '\n';
        } else {
            cout << -tai[n - l - 1] + tai[n - r - 1] << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}