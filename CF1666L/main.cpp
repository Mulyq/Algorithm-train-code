#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 10;
int n, m, s;
vector<vector<int>> e;
vector<bool> vis;
vector<int> a, b;
void dfs1(int t) {
    if(t == s) {
        cout << "Possible\n";
        for(auto x : a) {
            cout << x << ' ';
        }
        cout << '\n';
        vector<int> temp = b;
        reverse(temp.begin(), temp.end());
        for(auto x : temp) {
            cout << x << ' ';
        }
        cout << '\n';
        exit(0);
    }
    for(auto x : e[t] ) {
        if(!vis[x]) {
            b.push_back(x);
            vis[x] = 1;
            dfs1(x);
            vis[x] = 0;
            b.pop_back();
        }
    }
}
void dfs(int ss) {
    for(auto x : e[ss]) {
        if(!vis[x]) {
            a.push_back(ss);
            vis[ss] = 1;
            vis[s] = 0;
            dfs1(x);
            vis[s] = 1;
            dfs(x);
            vis[ss] = 0;
            a.pop_back();
        }
    }
}
void solve() {
    cin >> n >> m >> s;
    vis.resize(n + 1);
    e.resize(n + 1);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    vis[s] = 1;
    dfs(s);
    cout << "Impossible\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}