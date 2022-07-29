#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e6 + 10, mod = 998244353;
int n, m, s, k;
struct Edge {
    int v, w, t;
};
struct node {
    int v;
    ll dis;
    int pre;
    bool operator< (const node &a) const {
        return dis > a.dis;
    }
};

vector<Edge> e[MAXN];
ll dis[2][MAXN];
bool vis[2][MAXN];
set<int> S;
void solve() {
    S.clear();
    cin >> n >> m >> s >> k;
    for(int i = 1; i <= n; i ++) {
        e[i].clear();
        vis[0][i] = vis[1][i] = 0;
        dis[0][i] = dis[1][i] = 1e18 + 10;
        S.insert(i);
    }
    for(int i = 0; i < m; i ++) {
        int x, y, w, t;
        cin >> x >> y >> w >> t;
        e[x].push_back({y, w, t});   
    }
    priority_queue<node> q;
    dis[0][s] = 0;
    q.push({s, 0, 0});
    // 如果上一条边是普通边，按照一般最短路处理，如果是特殊边，下次边权-k，并遍历集合。
    while (q.size()) {
        ll u = q.top().v, d = q.top().dis, p = q.top().pre;
        // cout << u << ' ' << d << '\n';
        q.pop();
        if(vis[p][u]) continue;
        vis[p][u] = 1;
        S.erase(u);
        vector<bool> vis(n + 1);
        if(p == 1) {
            for(auto to : e[u]) {
                if(dis[to.t][to.v] > dis[p][u] + to.w - k) {
                    dis[to.t][to.v] = dis[p][u] + to.w - k;
                    q.push({to.v, dis[to.t][to.v], to.t});
                }
                vis[to.v] = 1;
            }
            vector<int> temp;
            for(auto v : S) if(!vis[v]) {
                dis[0][v] = dis[1][u];
                q.push({v, dis[0][v], 0});
            }
        } else {
            for(auto to : e[u]) {
                if(dis[to.t][to.v] > dis[p][u] + to.w) {
                    dis[to.t][to.v] = dis[p][u] + to.w;
                    q.push({to.v, dis[to.t][to.v], to.t});
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(dis[0][i] < 1e18 || dis[1][i] < 1e18) {
            cout << min(dis[0][i], dis[1][i]);
        } else {
            cout << "-1";
        }
        cout << ' ';
    }
    cout <<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}