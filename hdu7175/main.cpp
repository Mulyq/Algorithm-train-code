#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, ll> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
vector<vector<PII>> chG;
int dfn[MAXN], low[MAXN], belong[MAXN], deg[MAXN];
bool vis[MAXN];
stack<int> stk;
vector<int> tar[MAXN];
int tim, tag;
struct Edge {
    int to;
    ll e, p;
    bool operator< (const Edge &a) const {
        if(e != a.e) {
            return e > a.e;
        }
        return p < a.p;
    }
};
vector<vector<Edge>> G;
vector<vector<PII>> rG;
vector<ll> dis, rdis;

void Dij(int s) {
    dis.clear();
    dis.resize(n + 1, 1e18);
    vector<bool> vis(n + 1);
    priority_queue<Edge> q;
    dis[1] = 0;
    q.push({1, 0, 0});
    while(q.size()) {
        int u = q.top().to, e = q.top().e, p = q.top().p;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto v : G[u]) {
            if(dis[v.to] > dis[u] + v.e) {
                dis[v.to] = dis[u] + v.e;
                q.push({v.to, dis[v.to], 0});
                // rG[u].push_back({v.to, v.p});
            }
        }
    }
}

void add_edge() {
    for(int i = 1; i <= n; i ++) {
        if(dis[i] == 1e18) continue;
        for(auto it : G[i]) {
            int v = it.to, p = it.p , e = it.e;
            if(dis[v] == dis[i] + e) {
                rG[i].push_back({v, p});
            }
        }
    }
}

void init() {
    for(int i = 0; i <= n; i ++) {
        tar[i].clear();
        deg[i] = 0;
        dfn[i] = 0;
        low[i] = 0;
        belong[i] = 0;
        vis[i] = 0;
    }
    tim = 0;
    tag = 0;
}
void tarjan(int u, int f) {
    
    dfn[u] = low[u] = ++ tim;
    vis[u] = 1;
    stk.push(u);
    for(PII it : rG[u]) {
        int v = it.first;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            if(vis[v]) {
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if(low[u] == dfn[u]) {
        int now;
        do {
            now = stk.top();
            stk.pop();
            vis[now] = 0;
            tar[tag].push_back(now);
            belong[now] = tag;
        } while(now != u) ;
        tag ++;
    }
}
void tarjan_all() {
    for(int i = 1; i <= n; i ++) {
        if(!dfn[i]) {
            tarjan(i, i);
        }
    }
}
void regra() {
    for(int i = 1; i <= n; i ++) {
        int u = i;
        sort(rG[i].begin(), rG[i].end());
        rG[i].resize(unique(rG[i].begin(), rG[i].end()) - rG[i].begin());
        for(PII it : rG[i]) {
            int v = it.first;
            int x = belong[u], y = belong[v];
            if(x != y) {
                chG[x].push_back({y, it.second});
                deg[y] ++;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    G.resize(n + 1), rG.resize(n + 1), chG.resize(n + 1);
    for(int i = 0; i < m; i ++) {
        int a, b, e, p;
        cin >> a >> b >> e >> p;
        G[a].push_back({b, e, p});
    }
    Dij(1);
    add_edge();
    init();
    tarjan_all();
    regra();
    vector<int>dp(n + 1);
    int s = belong[1], t = belong[n];
    dp[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(PII it : chG[u])
        {
            int v = it.first, p = it.second;
            dp[v]=max(dp[u] + p, dp[v]);
            if(-- deg[v] == 0) q.push(v);
        }
    }
    cout << dis[n] << ' ' << dp[t] << '\n';
    G.clear();
    rG.clear();
    chG.clear();
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}