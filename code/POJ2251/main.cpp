#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int x, y, z;
struct node
{
    int x, y, z;
}be, en;

vector<vector<vector<int> > > g;
int bfs(node be) {
    vector<vector<vector<int> > > dis(x,vector<vector<int> >(y,vector<int>(z, -1)));
    const int dx[6] = {0,0,0,1,0,-1},dy[6] = {0,0,1,0,-1,0},dz[6] = {1,-1,0,0,0,0};
    queue<node> q;
    q.push(be);
    dis[be.x][be.y][be.z] = 0;
    while(q.size()) {
        node w = q.front();
        q.pop();
        for(int i = 0; i < 6; i ++) {
            if(w.x + dx[i] >= 0 && w.x + dx[i] < x &&  w.y + dy[i] >= 0 && w.y + dy[i] < y && w.z + dz[i] >= 0 && w.z + dz[i] < z)
                if(!g[w.x + dx[i]][w.y + dy[i]][w.z + dz[i]] && dis[w.x + dx[i]][w.y + dy[i]][w.z + dz[i]] == -1) {
                    dis[w.x + dx[i]][w.y + dy[i]][w.z + dz[i]] = dis[w.x][w.y][w.z] + 1;
                    q.push({w.x + dx[i], w.y + dy[i], w.z + dz[i]});
                }
        }
    }
    return dis[en.x][en.y][en.z];
}
void solve() {
    g.clear();
    g.resize(x,vector<vector<int> >(y,vector<int>(z, 0)));
    for(int i = 0; i < z; i ++ ) {
        for(int j = 0; j < x; j ++ ) {
            for(int k = 0; k < y; k ++) {
                char s;
                cin >> s;
                if(s == '#') g[j][k][i] = 1;
                else if(s == 'S') be = {j,k,i};
                else if(s == 'E') en = {j,k,i};
            }
        }
    }
    int res = bfs(be);
    if(res != -1) cout << "Escaped in "<< res << " minute(s)." << '\n';
    else cout << "Trapped!\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(cin >> z >> x >> y) {
        if(x == 0) break;
        solve();
    }
    return 0;
}