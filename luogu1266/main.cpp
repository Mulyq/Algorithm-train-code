#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
#define N 150
#define M 510
int n, m, D;
double dis[N][M];
bool vis[N][M];
PII pre[N][M];
struct Edge {
    int a, b, v, l;
};
vector<Edge> e[N];

void solve() {
    cin >> n >> m >> D;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= 510; j ++) {
            dis[i][j] = INF;
            vis[i][j] = 0;
        }
    }
    
    for(int i = 0; i < m; i ++) {
        int a, b, v, l;
        cin >> a >> b >> v >> l;
        e[a].push_back({a, b, v, l});        
    }
    struct node {
        int u;
        double d;
        int last;
        bool operator< (const node &a) const {
            return d > a.d;
        }
    };
    priority_queue<node> q;
    q.push({0, 0, 70});
    dis[0][70] = 0;
    // vis[0][70] = 1;
    while(q.size()) {
        int u = q.top().u;
        double d = q.top().d;
        int last = q.top().last;
        q.pop();
        if(vis[u][last]) continue;
        vis[u][last] = 1;
        for(auto [a, b, v, l] : e[u]) {
            if(!v) {
                v = last;
            }
            if(dis[b][v] > d + 1.0 * l / v) {
                dis[b][v] = d + 1.0 * l / v;
                pre[b][v] = {a, last};
                // cout << a << ' ' << b << ' ' << v << ' ' << 1.0 * l / v << ' ' << dis[b][v] <<'\n';
                q.push({b, dis[b][v], v});
            }
        }
    }
    vector<int> res(1, D);
    int k = 0;
    for(int i = 0; i <= 500; i ++) {
        if(dis[res.back()][i] < dis[res.back()][k]) {
            k = i;
        }
    }

    int now = pre[D][k].first, form = pre[D][k].second;
    while(1) {
        res.push_back(now);
        int temp = form;
        form = pre[now][form].second;
        now = pre[now][temp].first;
        if(res.back() == 0) break;
    }
    reverse(res.begin(), res.end());
    for(int x : res) {
        cout << x << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
}