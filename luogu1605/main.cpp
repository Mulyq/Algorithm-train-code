#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n, m;
int sx, sy, tx, ty;
int mp[7][7];
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, - 1, 0, 0};
int res;
void dfs (int x, int y) {
    if(x == tx && y == ty) {
        res ++;
        return ;
    }
    for(int i = 0; i < 4; i ++) {
        int X = x + dx[i], Y = y + dy[i];
        if(X < 1 || X > n || Y < 1 || Y > m || mp[X][Y]) continue;
        mp[x][y] = 1;
        dfs(X, Y);
        mp[x][y] = 0;
    }
}
void solve() {
    int k;
    cin >> n >> m >> k;
    cin >> sx >> sy >> tx >> ty;
    for(int i = 0; i < k; i ++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    dfs(sx, sy);
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}