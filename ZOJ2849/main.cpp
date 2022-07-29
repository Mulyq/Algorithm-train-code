#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int n, m;
vector<vector<int> > gra;
map<int, int > mp;
bool ban[510][510];
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, - 1, 0 , 0};
struct node {
    int x, y, d, xl;
    const bool operator < (const node & a) const {
        if(d != a.d) return d < a.d;
        return xl > a.xl;
    }
};
priority_queue <node> q;
void bfs(){
    while (q.size()) {
        node now = q.top();
        q.pop();
        int x = now.x, y = now.y ,d = now.d, xl = now.xl;
        if(ban[x][y] && d != 0) {
            continue;
        } else {
            if(mp.find(xl) == mp.end()) {
                mp[xl] = 1;
            }else {
                mp[xl] ++;
            }
            ban[x][y] = 1;
        }
        for(int i = 0; i < 4; i ++) {
            int X = x + dx[i], Y = y + dy[i];
            if(X >= 0 && X < n && Y >= 0 && Y < m) {
                if(gra[X][Y] < 0) {
                    q.push({X, Y, gra[X][Y], xl});
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m ; j ++) {
            ban[i][j] = 0;
        }
    }
    gra.resize(n, vector<int> (m));
    for(int i = 0; i < n; i ++) {
        for(int j  = 0; j < m; j ++) {
            cin >> gra[i][j];
            if(gra[i][j] >= 0) {
                q.push({i, j, 0, gra[i][j]});
                ban[i][j] = 1;
            }
        }
    }
    bfs();
    int k;
    cin >> k;
    while(k --) {
        int query;
        cin >> query;
        if(mp.find(query) == mp.end()) {
            cout << 0 << '\n';
        }else {
            cout << mp[query] << '\n';
        }
    }
    return 0;
}