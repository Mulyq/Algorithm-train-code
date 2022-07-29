#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    ll res = 0;
    queue<pair<ll, int>> q;
    ll all = 0;
    ll dob = 0;
    int tt = 0;
    for(int i = n; i >= 1; i --) {
        b[i] -= all;
        if(q.size()) {
            if(q.front().second == tt) {
                dob -= q.front().first;
                q.pop();
            }
            all -= dob;
        }
        tt ++;
        if(b[i] <= 0) continue;
        ll x = (b[i] + k - 1) / (1ll * k);
        if(i < k) {
            x = (b[i] + i - 1) / (i * 1ll);
            q.push({x, tt + i - 1});
            all += x * (i - 1);
        } else {
            q.push({x, tt + k - 1});
            all += x * (k - 1);    
        }
        dob += x;
        res += x;
        b[i] = 0;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}