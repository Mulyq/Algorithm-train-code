#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 10;
vector<int> e[MAXN];
int n, m, tim;
int low[MAXN], dfn[MAXN];
vector<int> res;
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++ tim;
    int child = 0;
    for(auto v : e[u]) if(v != fa) {
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u] && u != fa) {
                res.push_back(u);
            }
            child ++;
        }
        low[u] = min(low[u], dfn[v]);
    }
    if(child > 1 && u == fa) {
        res.push_back(u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i = 0; i < n; i ++) {
        if(!dfn[i]) {
            tarjan(i, i);
        }
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    cout << res.size() << '\n';
    for(int x : res) {
        cout << x + 1 << ' ';
    }
}