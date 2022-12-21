#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<vector<char>> G;

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m;
int sx, sy;
bool ok = 0;
void dfs(int x, int y, int c) {
    if(G[x][y] == '.') {
        G[x][y] = '0' + c;
    } else if(G[x][y] != '#') {
        cout << "Yes\n";
        exit(0);
    }
    for(int i = 0; i < 4; i ++) {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 0 && tx < n && ty >= 0 && ty < m && G[tx][ty] == '.') {
            dfs(tx, ty, c);        
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    G.resize(n);
    for(int i = 0 ; i < n; i ++) {
        G[i].resize(m);
        for(int j = 0; j < m; j ++) {
            cin >> G[i][j];
            if(G[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    for(int i = 0; i < 4; i ++) {
        int tx = sx + dx[i], ty = sy + dy[i];
        if(tx >= 0 && tx < n && ty >= 0 && ty < m && G[tx][ty] != '#') {
            dfs(tx, ty, i + 1);        
        }   
    }
    cout << "No\n";
    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < m; j ++) {
    //     cout << G[i][j];
    //     }
    //     cout << '\n';
    // }
}
