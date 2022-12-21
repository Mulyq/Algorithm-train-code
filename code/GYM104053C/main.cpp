#include<bits/stdc++.h>
using namespace std;
struct DSU {
    int N;
    vector<int> p;
    DSU(int n) {
        N = n;
        p.resize(n);
        for(int i = 0; i < n; i ++) {
            p[i] = i;
        }
    }
    int root(int x) {
        return p[x] == x ? x : p[x] = root(p[x]);
    }
    void merge(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return ;
        p[Y] = X;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> dis(n), w(n, 1);
    vector<vector<int>> G(n), rG(n);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        G[u].push_back(v), rG[v].push_back(u);
    }
    DSU dsu(n);
    for(int i = 1; i < n; i ++) {
        for(int j = 1; j < rG[i].size(); j ++) {
            dsu.merge(rG[i][0], rG[i][j]);
        }
    }
    vector<int> deg(n);
    vector<vector<int>> RG(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < G[i].size(); j ++) {
            RG[dsu.root(i)].push_back(dsu.root(G[i][j]));
            deg[dsu.root(G[i][j])] ++;
        }
    }
    queue<int> q;
    q.push(0);
    dis[0] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : RG[u]) {
            dis[v] = dis[u] + 1;
            if(! -- deg[v]) q.push(v);
        }
    }
    for(int i = 0; i < n; i ++) {
        if(deg[i]) {
            cout << "No\n";
            return ;
        }
    }
    for(int i = 1; i < n; i ++) {
        w[i] = dis[dsu.root(i)] - dis[dsu.root(rG[i][0])];
    }
    cout << "Yes\n";
    for(int i : w) {
        cout << i << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}