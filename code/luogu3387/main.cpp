#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e4 + 10;

int n, m;

struct Edge {
    int v;
    bool is_bri;
};

vector<Edge> e[MAXN];
int dfn[MAXN], low[MAXN];
bool vis[MAXN];
int tim = 0;
stack<int> stk;
vector<int> che[MAXN], scc[MAXN];
int belong[MAXN], val[MAXN], newval[MAXN], deg[MAXN];
int tag;

void init() {
    for(int i = 0; i < tag; i ++) {
        scc[i].clear();
    }
    for(int i = 0; i < n; i ++) {
        che[i].clear();
        e[i].clear();
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
    for(auto &[v, yes] : e[u]) {
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dfn[u] < low[v]) {
                yes = 1;
            }
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
            scc[tag].push_back(now);
            belong[now] = tag;
        } while(now != u);
        tag ++;
    }
}

void chgra() {
    for(int i = 0; i < n; i ++) {
        int u = i;
        for(auto [v, yes] : e[i]) {
            int x = belong[u], y = belong[v];
            if(x != y) {
                che[x].push_back(y);
                deg[y] ++;
            }
        }
    }
}

void tarjan_init() {
    tim = 0;
    for(int i = 0; i < n; i ++) {
        if(!dfn[i]) {
            tarjan(i, i);
        }
    }
}

int dp[MAXN];
void dfs(int x) {
    if(dp[x]) return ;
    dp[x] = newval[x];
    int mm = 0;
    for(auto v : che[x]) {
        if(!dp[v]) dfs(v);
        mm = max(mm, dp[v]);
    }
    dp[x] += mm;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    for(int i = 0; i < n; i ++) {
        cin >> val[i];
    }
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        e[u].push_back({v});
    }
    tarjan_init();
    // tarjan(0, 0);
    for(int i = 0; i < n; i ++) {
        newval[belong[i]] += val[i];
    }
    chgra();
    int res = 0;
    for(int i = 0 ; i < tag; i ++) {
        if(!dp[i]) {
            dfs(i);
        }
        res = max(res, dp[i]);
    }
    cout << res << '\n';
}