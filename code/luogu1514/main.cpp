#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
vector<vector<int>> G, vis;
vector<PII> lr;
const int dx[4] = {0, 0, 1, - 1}, dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int xl) {
    if(x == n - 1) {
        lr[xl].first = min(lr[xl].first, y);
        lr[xl].second = max(lr[xl].second, y);
    }
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
    lr.resize(m, {INF, -1});
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> G[i][j];
        }
    }
    for(int i = 0; i < m; i ++) {
        if(vis[0][i] == -1) {
            vis[0][i] = i;
            dfs(0, i, i);
        }
    }
    int cnt = 0;
    set<int> s;
    bool ok = 1;
    for(int i = 0; i < m; i ++) {
        if(vis[n - 1][i] == -1) {
            cnt ++;
            ok = 0;
        }
    }
    if(!ok) {
        cout << 0 << '\n' << cnt;
    } else {
        sort(lr.begin(), lr.end(), [&] (PII a, PII b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        int res = 1;
        int L = lr[0].first, R = lr[0].second, mx = R;
        for(int i = 1; i < m; i ++) {
            if(R == m - 1) break;
            if(lr[i].second > mx && lr[i].first <= R + 1) {
                mx = lr[i].second;
            } else if(lr[i].first > R) {
                res ++;
                R = mx;
                i --;
            }
        }
        cout << 1 << '\n' << res << '\n';
    }
}