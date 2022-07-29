#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<PII> a(m);
    for(int i = 0 ;i < m; i ++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    ll res = 0;
    int idx = 0;
    while (n) {
        res += min(n, a[idx].second) * a[idx].first;
        n -= min(n, a[idx].second);
        idx++;
    }
    cout << res << '\n';
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}