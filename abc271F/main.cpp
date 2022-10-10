#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n;
int G[22][22];
map<int, int> mp[22]; // ?
ll res; 
void dfs1(int x, int y, int p) {
    if(x + y > n - 1 || x >= n || y >= n) {
        return ;
    }
    if(x + y == n - 1) {
        mp[x][p] ++;
    }
    dfs1(x + 1, y, p ^ G[x + 1][y]);
    dfs1(x, y + 1, p ^ G[x][y + 1]);
}
void dfs2(int x, int y, int p) {
    if(x + y < n - 1 || x >= n || y >= n) {
        return ;
    }
    if(x + y == n - 1) {
        if(mp[x].find(p ^ G[x][y]) != mp[x].end()) {
            res += mp[x][p ^ G[x][y]];
        }
        // return;
    }
    dfs2(x - 1, y, p ^ G[x - 1][y]);
    dfs2(x, y - 1, p ^ G[x][y - 1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> G[i][j];
        }
    }
    dfs1(0, 0, G[0][0]);
    dfs2(n - 1, n - 1, G[n - 1][n - 1]);
    cout << res << '\n';
}