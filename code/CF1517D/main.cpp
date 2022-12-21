#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 2e5 + 10, mod = 998244353;
int dis[510][510][12];
struct dir {
    int up, dn, le, ri;
    dir() {
        up = dn = le = ri = INF;
    }
};
vector<vector<dir>> G;
int n, m, k;
int dfs(int x, int y, int c) {
    if(c <= 0) return 0;
    if(dis[x][y][c] != INF) return dis[x][y][c];
    if(x - 1 >= 0) dis[x][y][c] = min(dis[x][y][c], dfs(x - 1, y, c - 1) + G[x][y].up);
    if(y - 1 >= 0) dis[x][y][c] = min(dis[x][y][c], dfs(x, y - 1, c - 1) + G[x][y].le);
    if(x + 1 <  n) dis[x][y][c] = min(dis[x][y][c], dfs(x + 1, y, c - 1) + G[x][y].dn);
    if(y + 1 <  m) dis[x][y][c] = min(dis[x][y][c], dfs(x, y + 1, c - 1) + G[x][y].ri);
    return dis[x][y][c];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dis, 0x3f, sizeof dis);
    cin >> n >> m >> k;
    if(k & 1) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
    } else {
        k /= 2;
        G.resize(n, vector<dir> (m));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m - 1; j ++) {
                int x;
                cin >> x;
                G[i][j].ri = G[i][j + 1].le = x;
            }
        }
        for(int i = 0; i < n - 1; i ++) {
            for(int j = 0; j < m ;j ++) {
                int x;
                cin >> x;
                G[i][j].dn = G[i + 1][j].up = x;
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m;j ++) {
                cout << dfs(i, j, k) * 2 << ' ';
            }
            cout << '\n';
        }
    }
}