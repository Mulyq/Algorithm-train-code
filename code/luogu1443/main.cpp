#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
void solve() {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m ,&x, &y);
    vector<vector<int>> dis(n + 1, vector<int> (m + 1, -1));
    queue<PII> q;
    q.push({x, y});
    dis[x][y] = 0;
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i ++) {
            int X = x + dx[i], Y = y + dy[i];
            if(X < 1 || X > n || Y < 1 || Y > m) {
                continue;
            }
            if(dis[X][Y] == - 1) {
                dis[X][Y] = dis[x][y] + 1;
                q.push({X, Y});
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <=  m; j ++) {
            printf("%-5d", dis[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}