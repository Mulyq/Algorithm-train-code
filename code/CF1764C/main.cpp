#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e6 + 10, mod = 998244353;
void solve() {
    int n;
    cin >> n;
    ll res = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for(int i = 0; i < n; i ++) {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    vector<int> b(temp.size() + 1);
    for(int i = 0; i < a.size(); i ++) {
        b[a[i]] ++;
    }
    for(int i = 0; i < b.size(); i ++) {
        res += b[i] / 2;
    }
    for(int i = 1; i < b.size(); i ++) {
        b[i] += b[i - 1];
    }
    for(int i = 1; i < b.size() - 1; i ++) {
        res = max(res, 1ll * b[i] * (b[b.size() - 1] - b[i]));
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
}