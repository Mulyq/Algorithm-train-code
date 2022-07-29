#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<int>  a, vis;
vector<vector<int>> b, e;
bool cmp(int  a, int  b) {
    return a > b;
}
void dfs(int x) {
    vis[x] = 1;
    for(auto it : e[x]) {
        if(!vis[it]) {
            dfs(it);
            vector<int> tmp(b[x].size() + b[it].size());
            merge(b[x].begin(), b[x].end(), b[it].begin(), b[it].end(), tmp.begin(), cmp);
            if(tmp.size() > 50) {
                tmp.resize(50);
            }
            b[x] = tmp;
        }
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    vis.resize(n + 1, 0);
    a.resize(n + 1), b.resize(n + 1), e.resize(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i].push_back(a[i]);
    }
    for(int i = 1; i < n; i ++) {
        int v, u;
        cin >> v >> u;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(1);
    while(q --) {
        int v, k;
        cin >> v >> k;
        cout << b[v][k - 1] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}