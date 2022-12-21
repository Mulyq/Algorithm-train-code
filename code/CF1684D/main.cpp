#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<PII>val(n);
    
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        val[i].first = - a[i] + (n - 1 - i);
        val[i].second= i;
    }
    sort(val.begin(), val.end());
    int ex = 0;
    ll res = 0;
    vector<bool> vis(n);
    vector<int> b(n + 1);
    for(int i = 0; i < k ; i ++) {
        vis[val[i].second] = 1;
        b[val[i].second] += 1;
    }
    for(int i = 1; i <= n; i ++) {
        b[i] += b[i - 1];
    }
    for(int i = 0; i < n; i ++) {
        if(vis[i]) continue;
        else {
            res += a[i] + b[i];
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