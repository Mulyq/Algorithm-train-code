#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> deg(n);
    for(int i = 0; i < n; i ++) {
        int m;
        cin >> m;
        while(m --) {
            int v;
            cin >> v;
            v --;
            G[v].push_back(i);
            deg[i] ++;
        }
    }
    vector<int> dp(n);
    queue<int> q;
    for(int i = 0; i < n; i ++) {
        if(!deg[i]) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : G[u]) {
            if(! -- deg[v]) {
                q.push(v);
            }
            if(v < u) {
                dp[v] = max(dp[v], dp[u] + 1);
            } else {
                dp[v] = max(dp[v], dp[u]);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i ++) {
        if(deg[i]) {
            cout << -1 << '\n';
            return ;
        }
        res = max(res, dp[i]);
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