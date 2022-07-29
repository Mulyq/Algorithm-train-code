#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int n, m;
vector<vector<int>> gra;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, - 1, 0, 0};
bool bfs(int t) {
    vector<vector<bool>> vis(n, vector<bool> (m));
    queue<PII> q;
    for(int i = 0; i < m; i ++) {
        q.push({0, i});
        vis[0][i] = 1;
    }
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        if(x == n - 1) return 0;
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int X = x + dx[i], Y = y + dy[i];
            if(X < 0 || X >= n || Y < 0 || Y >= m) continue;
            if(gra[X][Y] <= t && vis[X][Y] == 0) {
                q.push({X, Y});
                vis[X][Y] = 1;
            }
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    gra.resize(n, vector<int> (m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> gra[i][j];
        }
    }
    int l = 0, r = 1001;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if (bfs(mid)) l = mid;
        else r = mid - 1; 
    }
    cout << r + 1;
    return 0;
}