#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<vector<PII> > e;
int dis[2][5010];
bool vis[2][5010];
int n, m;
struct node {
    int v, d;
    const bool operator > (const node &a) const {
        return d > a.d;
    }
};
void Dij() {
    for(int i = 1; i <= n; i ++) {
        dis[1][i] = dis[0][i] = INF;
    }
    priority_queue<node, vector<node>, greater<node> > q;
    node temp ;
    temp.v = 1, temp.d = 0;
    q.push(temp);
    dis[0][1] = 0;
    while(q.size()) {
        int v = q.top().v, d = q.top().d;
        q.pop();
        
        if(dis[1][v] < d) continue;

        for(int i = 0; i < e[v].size(); i ++) {
            PII u = e[v][i];
            int d2 = u.second + d;
            if(d2 < dis[0][u.first]) {
                swap(dis[0][u.first], d2);
                node temp;
                temp.v = u.first, temp.d = dis[0][u.first];
                q.push(temp);
            }
            if(dis[1][u.first] > d2 && dis[0][u.first] < d2) {
                dis[1][u.first] = d2;
                node temp;
                temp.v = u.first, temp.d - dis[1][u.first];
                q.push(temp);
            }
        }
    }
}
void solve() {
    
    cin >> n >> m;
    e.resize(n + 1);
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }
    Dij();
    // for(int i = 1; i <= n; i ++) {
    //     cout << dis[1][i] << ' ';
    // }
    cout << dis[1][n];
}
int main(){
    int _ = 1;
    //scanf("%d", &_);
    while(_ --) {
        solve();
    }
    return 0;
}