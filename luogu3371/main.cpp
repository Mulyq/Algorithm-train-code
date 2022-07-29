#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
vector<vector<PII>> e;
vector<int> dis;
int n, m, s;
void Dij(int s) {
    dis.resize(n + 1, INT_MAX);
    vector<bool> vis(n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    dis[s] = 0;
    while (q.size()) {
        int f = q.top().second, d = q.top().first;
        q.pop();
        if(vis[f]) continue;
        vis[f] = 1;
        for(auto t : e[f]) {
            if(dis[t.first] > dis[f] + t.second) {
                dis[t.first] = dis[f] + t.second;
                q.push({dis[t.first] ,t.first});
            }
        }   
    }
}
void solve() {
    cin >> n >> m >> s;
    e.resize(n + 1);
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    Dij(s);
    for(int i = 1; i <= n; i ++) {
        cout << dis[i] <<' ';
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
}