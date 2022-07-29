#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int n, p1, p2, p3;
vector<vector<char>> gra;
int ans = INF;
struct node {
    int v1, v2, v3, dis;
};
void bfs() {
    int ban[55][55][55];
    memset(ban, -1, sizeof ban);
    queue<node> q;
    q.push({p1, p2, p3, 0});
    ban[p1][p2][p3] = 1;
    while(q.size()) {
        node temp = q.front();
        q.pop();
        int v1 = temp.v1, v2 = temp.v2, v3 = temp.v3, dis = temp.dis;
        if(v1 == v2 && v2 == v3 ) {
            ans = dis;
            return ;
        }
        for(int i = 1; i <= n; i ++) {
            if(i == v1 || gra[v1][i] != gra[v2][v3]) continue;
            if(ban[i][v2][v3] != -1) continue;
            q.push({i, v2, v3, dis + 1});
            ban[i][v2][v3] = 1;
        }
        for(int i = 1; i <= n; i ++) {
            if(i == v2 || gra[v2][i] != gra[v1][v3]) continue;
            if(ban[v1][i][v3] != -1) continue;
            q.push({v1, i, v3, dis + 1});
            ban[v1][i][v3] = 1;
        }
        for(int i = 1; i <= n; i ++) {
            if(i == v3 || gra[v3][i] != gra[v2][v1]) continue;
            if(ban[v1][v2][i] != -1) continue;
            q.push({v1, v2, i, dis + 1});
            ban[v1][v2][i] = 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    while(cin >> n) {
        ans = INF;
        if(n == 0)break;
        gra.resize(n + 1, vector<char> (n + 1));
        cin >> p1 >> p2 >> p3;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                cin >> gra[i][j];
            }
        }
        bfs();
        if(ans == INF) {
            cout << "impossible\n";
        } else {
            cout << ans << '\n';
        }
        gra.clear();
    }
    return 0;
}