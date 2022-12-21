#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 2e5 + 10, mod = 1e9 + 7;
int n, m, s, t;
int dis[2][N], cnt[2][N];
bool vis[2][N];
void Dij(int s, vector<vector<int>> e) {
    for(int i = 0; i <= n; i++) {
        cnt[0][i] = cnt[1][i] = vis[0][i] = vis[1][i] = 0;
        dis[0][i] = dis[0][i] = INF;
    }
    struct node {
        int u, d, type;
        const bool operator> (const node & a) const {
            return d > a.d;
        }
    };
    priority_queue<node, vector<node> ,greater<node>> q;
    q.push({s, 0, 0});
    dis[0][s] = 0;
    cnt[0][s] = 1;
    while(q.size()) {
        auto temp = q.top();
        q.pop();
        int u = temp.u, d = temp.d, type = temp.type;
        if(vis[type][u]) continue;
        vis[type][u] = 1;
        for(auto v : e[u]) {
            if(dis[0][v] > d + 1) {
                dis[1][v] = dis[0][v];
                cnt[1][v] = cnt[0][v];
                q.push({v, dis[1][v], 1});
                dis[0][v] = dis[0][u] + 1;
                cnt[0][v] = cnt[type][u];
                q.push({v, dis[0][v], 0});
            } else if(dis[0][v] == d + 1) {
                cnt[0][v] = (cnt[0][v] + cnt[type][u]) % mod;
            } else if(dis[1][v] > d + 1) {
                dis[1][v] = d + 1;
                cnt[1][v] = cnt[type][u];
                q.push({v, d + 1, 1});
            } else if(dis[1][v] == d + 1) {
                cnt[1][v] = (cnt[1][v] + cnt[type][u]) % mod;
            }
        }  
    }
}
void solve() {
    cin >> n >> m >> s >> t;
    vector<vector<int>> e(n + 1);
    for(int i = 0; i < m; i ++) {
        int v, u;
        cin >> v >> u;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    Dij(s, e);
    ll res = cnt[0][t];
    if(dis[1][t] == dis[0][t] + 1) {
        res = (res + cnt[1][t]) % mod;
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
};