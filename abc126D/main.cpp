#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<vector<PII>> G;
vector<int>  color;
int n;
void dfs(int u, int p, int d) {
    if(d & 1) {
        color[u] = 1 - color[p];
    } else {
        color[u] = color[p];
    }
    for(auto &[v, w] : G[u]) if(v != p) {
        dfs(v, u, w);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    G.resize(n), color.resize(n);
    for(int i = 1; i < n; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(0, 0, 0);
    for(int i : color) {
        cout << i << '\n';
    }
}