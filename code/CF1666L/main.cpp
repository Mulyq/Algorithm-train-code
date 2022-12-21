#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m, s;
vector<vector<int>> G, rG;
vector<int> pre;
vector<bool> vis;
int t;
int l1, l2;
void rdfs(int u, int p) {
    l2 ++;
    if(u == s) {
        cout << "Possible\n";
        cout << l1 << '\n';
        vector<int> temp;
        int now = t;
        do {
            temp.push_back(now);
            now = pre[now];
        } while(now != s);
        temp.push_back(s);
        reverse(temp.begin(), temp.end());
        for(int v : temp) {
            cout << v + 1 << ' ';
        }
        cout <<'\n';
        cout << l2 << '\n';
        now = s;
        temp.clear();
        do {
            temp.push_back(now);
            now = pre[now];
        } while(now != t);
        temp.push_back(t);
        for(int v : temp) {
            cout << v  + 1 << ' ';
        }
        exit(0);
    }
    for(int v : rG[u]) if(v != p) {
        if(pre[v] == - 1 && !vis[v]) {
            pre[v] = u;
            vis[v] = 1;
            rdfs(v, u);
            pre[v] = - 1;
        }
    }
    l2 --;
}
void dfs(int u, int p) {
    l1 ++;
    if(u != s) {
        l2 = 0;
        t = u;
        rdfs(u, p);
    }
    for(int v : G[u]) {
        if(pre[v] == -1) {
            pre[v] = u;
            dfs(v, u);
            pre[v] = -1;
        }
    }
    l1 --;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    s --;
    G.resize(n), rG.resize(n);
    pre.resize(n, -1);
    vis.resize(n, 0);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    dfs(s, s);
    cout << "Impossible\n";
}