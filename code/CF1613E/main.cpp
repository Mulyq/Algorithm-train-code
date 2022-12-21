#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int xx, yy;
void solve() {
    cin >> n >> m;
    vector<vector<char>> G(n, vector<char> (m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> G[i][j];
            if(G[i][j] == 'L') {
                xx = i, yy = j;
            }
        }
    }
    queue<PII> q;
    for(int i = 0; i < 4; i ++) {
        int X = xx + dx[i], Y = yy + dy[i];
        if(X >= 0 && X < n && Y >= 0 && Y < m && G[X][Y] == '.') {
            q.push({X, Y});
        }
    }
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        vector<PII> t;
        for(int i = 0; i < 4; i ++) {
            int X = x + dx[i], Y = y + dy[i];
            if(X >= 0 && X < n && Y >= 0 && Y < m && G[X][Y] == '.') {
                t.push_back({X, Y});
            }
        }
        if(t.size() <= 1) {
            G[x][y] = '+';
            for(PII v : t) {
                q.push(v);
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout << G[i][j];
        }
        cout << '\n';
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