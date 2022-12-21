#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
const int mod = 1e5 + 3;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vector<int> vis(n + 1), dp(n + 1);
    vector<int> d(n + 1);
    vis[1] = 1, d[1] = 0, dp[1] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto it : e[u]) {
            if(!vis[it]) {
                vis[it] = 1;
                d[it] = d[u] + 1;
                q.push(it);
            }
            if(d[it] == d[u] + 1) {
                dp[it] = (dp[u] + dp[it]) % mod;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << dp[i] << '\n';
    }
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
};