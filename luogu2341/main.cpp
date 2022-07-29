#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
int n, m;
struct Edge {
    int v;
    bool is_bri; //是否为桥（割边）
};
vector<Edge> e[MAXN];
// tarjan 需要定义的
int dfn[MAXN], low[MAXN];
bool vis[MAXN];
int tim = 0;
stack<int> stk;
// 缩点需要定义的
int tag;                                        // 强连通分量个数
vector<int> tar[MAXN];                          // 每个强连通分量的点集
int belong[MAXN];                               // 每个点属于哪个强连通分量
int deg[MAXN];                                  // 缩点后新图每个点的出度
vector<int> che[MAXN];                          // 缩点后的图
// 初始化数组
void init() {
    for(int i = 0; i < tag; i ++) {
        tar[i].clear();
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
        if(!dfn[v]) {                           // 父子边
            tarjan(v, u);
            low[u] = min(low[u], low[v]);       // 更新low
            if(dfn[u] < low[v]) {               // v不能通过u到达更早的祖宗
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
            tar[tag].push_back(now);
            belong[now] = tag;
        } while(now != u);
        tag ++;
    }
}
// 给定图不连通
void tarjan_all() {
    for(int i = 0; i < n; i ++) {
        if(!dfn[i]) {
            tarjan(i, i);
        }
    }
}
// 缩点
void regra() {
    for(int i = 0; i < n; i ++) {
        int u = i;
        for(auto [v, yes] : e[i]) {
            int x = belong[u], y = belong[v];
            if(x != y) {
                che[x].push_back(y);
                deg[x] ++;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        e[u].push_back({v});
    }
    tarjan_all();
    regra();
    int res = 0;
    for(int i = 0; i < tag; i ++) {
        if(deg[i] == 0) {
            if(!res)
                res = tar[i].size();
            else {
                res = 0;
                break;
            }
        }
    }
    cout << res << '\n';
    return 0;
}