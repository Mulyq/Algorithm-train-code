#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
vector<vector<int> > e;
vector<int> dis;
int n, m, k;
void Dij() {
    dis.resize(n + 1, INF);
    vector<int> vis(n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    dis[1] = 0;
    while(q.size()) {
        PII  u = q.top();
        q.pop();
        int d = u.first, v = u.second;
        for(auto x : e[v]) {
            if(vis[x]) continue;
            vis[x] = 1;
            if(dis[x] > dis[v] + 2) {
                dis[x] = dis[v] + 2;
                q.push({dis[x], x});
            }
        }
    }
}
void solve() {
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for(int i = 2; i <= n; i ++) {
        cin >> a[i];
    }
    e.resize(n + 1);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    Dij();
    vector<vector<int>> dp(n + 1, vector<int> (k + 1));
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= k; j ++) {
            dp[i][j] = dp[i - 1][j];
            if(j - dis[i] >= 0) dp[i][j] = max(dp[i][j], dp[i][j - dis[i]] + a[i]);
        }
    }
    for(int i = 1; i <= k; i ++) {
        cout << dp[n][i] << ' ';
    }
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