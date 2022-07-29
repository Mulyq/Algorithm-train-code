#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    if(m <= n) {
        cout << n - m << '\n';
        return ;
    }
    ll res = 1e18;
    for(int i = 1; i <= n; i ++) {
        res = min(res, n - m + (ll)((m - 1) / i)  * i);
        i = (m - 1) / ((m - 1) / i);
    }
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