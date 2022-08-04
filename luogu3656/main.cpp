#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m;
vector<vector<int>> G;
vector<vector<int>> vis;
int res = INF;
void dfs(int x, int y, int yes, int all) {
    if(all >= res) {
        return ;
    }
    if(x == n - 1 && y == n - 1) {
        res = min(res, all);
        return ;
    }
    // cout << x << ' ' << y << ' ' << all << '\n';
    vis[x][y] = 1;
    for(int i = 0; i < 4; i ++) {
        int X = x + dx[i], Y = y + dy[i];
        if(X >= 0 && X < n && Y >= 0 && Y < n && !vis[X][Y]) {
            if(G[x][y] == G[X][Y]) {
                dfs(X, Y, 0, all);
            } else if(G[X][Y] != -1) {
                dfs(X, Y, 0, all + 1);
            } else if(!yes) {
                G[X][Y] = G[x][y];
                dfs(X, Y, 1, all + 2);
                G[X][Y] = -1;
            }
        }
    }
    vis[x][y] = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    G.resize(n, vector<int> (n, -1));
    vis.resize(n, vector<int> (n));
    for(int i = 0; i < m; i ++) {
        int x, y, c;
        cin >> x >> y >> c;
        x --, y --;
        G[x][y] = c;
    }
    dfs(0, 0, 0, 0);
    if(res != INF)
    cout << res << '\n';
    else {
        cout << -1 << '\n';
    }
}