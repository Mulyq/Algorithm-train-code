#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<vector<int> > gra (5, vector<int> (5));
vector<vector<PII> > rec(5, vector<PII> (5, {-1, -1}));
void bfs() {
    vector<vector<int> > ban (5, vector<int> (5));
    const int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
    queue<PII> q;
    q.push({0, 0});
    while(!q.empty()) {
        PII temp = q.front();
        int x = temp.first, y = temp.second;
        ban[x][y] = 1;
        for(int i = 0; i < 4; i ++) {
            int X = x + dx[i], Y = y + dy[i];
            if(X < 0 || X >= 5 || Y < 0 || Y >= 5 || ban[X][Y]) continue;
            if(!gra[X][Y]) {
                q.push({X, Y});
                rec[X][Y] = temp;
            }
        }
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 5; j ++) {
            cin >> gra[i][j];
        }
    }
    bfs();
    vector<PII> res;
    PII now;
    now.first = 4, now.second = 4;
    while(now.first != -1 && now.second != -1) {
        res.push_back(now);
        now = rec[now.first][now.second];
    }
    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i ++) {
        PII x = res[i];
        cout << '(' << x.first << ", " << x.second << ')' << '\n';
    }
    return 0;
}