#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> nex(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        nex[x] = i;
    }
    int res = 0;
    bool ok = 0;
    vector<int> vis(n + 1);
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            int len = 0;
            int t = i;
            set<int> s;
            while(!vis[t]) {
                // cout << t << ' ';
                vis[t] = 1;
                len ++;
                s.insert(t);
                if(s.find(t + 1) != s.end() || s.find(t - 1) != s.end()) {
                    ok = 1;
                }
                t = nex[t];
            }
            res += len - 1;
        }
    }
    if(ok) res --;
    else res ++;
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