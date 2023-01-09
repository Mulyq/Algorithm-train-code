#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
#define int ll
void solve() {
    int n, m;
    cin >> n >> m;
    m --;
    int res = 0;
    vector<ll> a(n);
    priority_queue<int, vector<int>, greater<int>> q;
    ll all = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(i > m) {
            q.push(a[i]);
            all += a[i];
            while(all < 0) {
                ll x = q.top();
                q.pop();
                all -= 2 * x;
                res ++;
            }
        }
    }
    priority_queue<int> p;
    ll mi = 0;
    for(int i = 0; i <= m; i ++) {
        mi += a[i];
    }
    all = mi;
    for(int i = m; i >= 1; i --) {
        p.push(a[i]);
        all -= a[i];
        while(all < mi) {
            int x = p.top();
            p.pop();
            mi -= 2 * x;
            res ++;
        }
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}