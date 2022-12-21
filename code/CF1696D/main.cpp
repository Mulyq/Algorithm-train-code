#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    int res = 0;
    int now = 0;
    while(now + 1 < n) {
        if(a[now] < a[now + 1]) {
            int mx = a[now + 1];
            int xl = now + 1;
            auto it = mp.lower_bound(mx);
            for(; it != mp.end(); it ++) {
                if((*it).second > xl) {
                    xl  = (*it).second;
                }
            }
            now = xl;
        } else {
            int mn = a[now + 1];
            int xl = now + 1;
            auto it = mp.lower_bound(mn);
            for(; it != mp.begin(); it --) {
                if((*it).second > xl) {
                    xl = (*it).second;
                }
            }
            if((*it).second > xl) {
                xl = (*it).second;
            }
            now = xl;
        }
        res ++;
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