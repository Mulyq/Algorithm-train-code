#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e5 + 10, mod = 998244353;
int m, s, t;
char G[2][MAXN];
bool vis[3][MAXN];
/*
0 向下
1 向上
2 向左
3 向右
*/
bool res = 0;
void dfs(int x, int y, int type) {
    if(vis[x][y]) {
        return;
    }
    if(x < 0 || x >= 2 || y < 0 || y >= m) {
        if(x == 2 && y == t) {
            res = 1;
        }
        return;
    }
    vis[x][y] = 1;
    if(type == 1) {
        if(G[x][y] == 'I') {
            dfs(x + 1, y, type);
        } else {
            if(y >= 1)
                dfs(x, y - 1, 2);
            dfs(x, y + 1, 3);
        }
    } else if(type == 2) {
        if(G[x][y] == 'I') {
            if(y >= 1)
                dfs(x, y - 1, type);
        } else {
            if(x >= 1)
                dfs(x - 1, y, 0);
            dfs(x + 1, y, 1);
        }
    } else if(type == 3) {
        if(G[x][y] == 'I') {
            dfs(x, y + 1, type);
        } else {
            if(x >= 1)
                dfs(x - 1, y, 0);
            dfs(x + 1, y, 1);
        }
    } else {
        if(G[x][y] == 'I') {
            if(x >= 1)
                dfs(x - 1, y, type);
        } else {
            if(y >= 1)
                dfs(x, y - 1, 2);
            dfs(x, y + 1, 3);
        }
    }
    vis[x][y] = 0;
}
void solve() {
    cin >> m >> s >> t;
    s --, t --;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> G[i][j];
        }
    }
    res = 0;
    dfs(0, s, 1);
    if(res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}