#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
// #include <tuple>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 1e6 + 10;
vector<ll> w, dis;
vector<vector<PII> > e;
void Dijkstra(int n, int s) {
    dis.clear();
    dis.resize(n + 1, INF);
    vector<int> vis(n + 1, 0);
    dis[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, s}); 
    while(!q.empty()) {
        PII x = q.top();
        q.pop();
        if(vis[x.second]) continue;
        else vis[x.second] = 1;
        for(int i = 0; i < e[x.second].size(); i ++) {
            ll a = e[x.second][i].first, b = e[x.second][i].second;
            if(dis[a] > dis[x.second] + b) {
                dis[a] = dis[x.second] + b;
                q.push({dis[a], a});
            }
        }
    }
}
void solve() {
    int n, m;
    scanf("%d%d",&n, &m);
    w.resize(n + 1);
    e.resize(n + 1);
    for(int i = 1; i <= n; i ++) {
        scanf("%lld",&w[i]);
    }
    for(int i = 0; i < m; i ++) {
        ll v, u, x;
        scanf("%lld%lld%lld",&v, &u, &x);
        e[v].push_back({u, x});
        e[u].push_back({v, x});
    }
    Dijkstra(n, 1);
    ll res = 0;
    for(int i = 1; i <= n; i ++) {
        if(dis[i] == INF) {
            printf("No Answer\n");
            return ;
        }
        res += dis[i] * w[i];
    }
    printf("%lld\n",res);
    return;
}
int main() {
    int T = 1;
    scanf("%d",&T);
    while(T --) {
        solve();
    }
    return 0;
}