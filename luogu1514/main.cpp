#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
vector<vector<int>> G, vis;
const int dx[4] = {0, 0, 1, - 1}, dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int xl) {
    for(int i = 0; i < 4; i ++) {
        int X = x + dx[i], Y = y + dy[i];
        if(X >= 0 && X < n && Y >= 0 && Y < m && vis[X][Y] != xl && G[x][y] > G[X][Y]) {
            vis[X][Y] = xl;
            dfs(X, Y, xl);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    G.resize(n, vector<int> (m));
    vis.resize(n, vector<int> (m, - 1));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> G[i][j];
        }
    }
    for(int i = 0; i < m; i ++) {
        if(vis[0][i] == - 1) {
            // vis[0][i] = i;
            dfs(0, i, i);
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout << vis[i][j] << ' '  ;
        }
        cout << '\n';
    }
    bool ok = 1;
    set<int> S;
    int cnt = 0;
    for(int i = 0; i < m; i ++) {
        if(vis[n - 1][i] != -1) {
            cnt ++;
        } else {
            ok  = 0;
        }
    }
    if(ok) {
        cout << ok << '\n';
        vector<int> tt;
        for(int i = 0; i < m; i ++) {
            if(vis[0][i] == -1) {
                tt.push_back(i);
            }
        }
        sort(tt.begin(), tt.end(), [&] (int a, int b) {
            return G[0][a] < G[0][b];
        });
        for(int v : tt) {
            dfs(0, v, v);
        }
        for(int i = 0; i < m; i ++) {
            S.insert(vis[n - 1][i]);
        }
        cout << S.size() << '\n';
    } else {
        cout << ok << '\n';
        cout << m - cnt << '\n';
    }
}